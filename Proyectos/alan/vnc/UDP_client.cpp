#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <string.h>
#include <vector>
#include <fstream>
#include <thread>
#include <atomic>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <cassert>
#include "DatagramPacket.h"
#include "DatagramSocket.h"
#include "Message.h"
#include "Info.h"
#include "Part.h"

const uint16_t port = 15645;

using namespace std;

map<pair<string, string>, ofstream> files;
map<pair<string, string>, atomic<int>> cnt;
map<string, atomic<int>> pending;

void request_capture(DatagramSocket & client, uint32_t i, int t, int q) {
	struct in_addr addr;
	addr.s_addr = htonl(i);
	string ip = string(inet_ntoa(addr));
	string dir = "captures/" + ip;
	mkdir(dir.c_str(), 0700);
	Message *msg = new Message();
	while(true) {
		while (pending[ip] >= 10) {
			this_thread::sleep_for(chrono::seconds(1));
		}
		msg->action = 0;
		memcpy(msg->data, &q, sizeof(int));
		DatagramPacket p((char*)msg, sizeof(Message), ip, port);
		client.send(p);
		this_thread::sleep_for(chrono::seconds(t));
	}
}

void request_parts(DatagramSocket & client, string ip, uint16_t port, Info *info) {
	pending[ip]++;
	size_t size = info->size;
	string name(info->name);
	files[{ip, name}].open("captures/" + ip + "/" + name);
	cnt[{ip, name}] = 0;
	int parts = (size + part_size - 1) / part_size;
	cout << ip << " " << name << ", size=" << size << ", parts=" << parts << "\n";
	size_t pos = 0;
	Message *msg = new Message();
	msg->action = 2;
	Part *part = new Part();
	int attempts = 0;
	for (int i = 0; i < parts; ++i) {
		if (attempts == 5) {
			break;
		}
		part->id = i;
		if (i < parts-1) {
			part->size = part_size;
		} else {
			if (size % part_size == 0) {
				part->size = part_size;
			} else {
				part->size = size % part_size;
			}
		}
		part->offset = pos;
		strcpy(part->name, info->name);
		pos += part_size;
		memcpy(msg->data, part, sizeof(Part));
		DatagramPacket p((char*)msg, sizeof(Message), ip, port);
		client.send(p);
		int time = 0;
		while (cnt[{ip, name}] != i+1) {
			if (time == 100) {
				i--;
				pos -= part_size;
				attempts++;
				break;
			}
			this_thread::sleep_for(chrono::milliseconds(10));
			time++;
		}
	}
	files[{ip, name}].close();
	files.erase({ip, name});
	cnt.erase({ip, name});
	cout << ip << " " << name << " " << (attempts == 5 ? "error" : "completed") << "\n";
	msg->action = 4;
	memcpy(msg->data, info, sizeof(Info));
	DatagramPacket p((char*)msg, sizeof(Message), ip, port);
	client.send(p);
	pending[ip]--;
	delete msg;
	delete part;
	delete info;
}

void write_part(string ip, Part *part) {
	string name(part->name);
	auto & file = files[{ip, name}];
	file.seekp(part->offset);
	file.write(part->data, part->size);
	cnt[{ip, name}] = part->id + 1;
}

void handle_reply(DatagramSocket & client) {
	Message *msg = new Message();
	while(true) {
		DatagramPacket p((char*)msg, sizeof(Message));
		client.receive(p);
		string server_ip = p.getAddress();
		uint16_t server_port = p.getPort();
		if (port != server_port) {
			continue;
		}
		if (msg->action == 1) {
			Info *info = new Info();
			memcpy(info, msg->data, sizeof(Info));
			thread th(request_parts, ref(client), server_ip, server_port, info);
			th.detach();
		} else if(msg->action == 3) {
			Part *part = new Part();
			memcpy(part, msg->data, sizeof(Part));
			write_part(server_ip, part);
			delete part;
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc != 5) {
		cout << "USAGE:\n";
		cout << "    UDP_client <t> <IP> <n> <q>\n";
		cout << "\n";
		cout << "ARGS:\n";
		cout << "    <t>    Period of capture in seconds\n";
		cout << "    <IP>   The first IP address\n";
		cout << "    <n>    The number of IP addresses\n";
		cout << "    <q>    Quality of the captures (between 1 and 100)\n";
		exit(-1);
	}

	int t = stoi(argv[1]);
	int n = stoi(argv[3]);
	int q = stoi(argv[4]);
	if (n < 1 || n > 30) {
		cout << "The number of hosts must be between 1 and 30\n";
		exit(-1);
	}

	mkdir("captures", 0700);

	uint32_t firstIP = ntohl(inet_addr(argv[2]));
	uint32_t lastIP = firstIP + n-1;
	DatagramSocket client;

	vector<thread> requests;
	for (uint32_t i = firstIP; i != lastIP+1; ++i) {
		requests.emplace_back(request_capture, ref(client), i, t, q);
	}
	thread handler(handle_reply, ref(client));
	for (uint32_t i = firstIP; i != lastIP+1; ++i) {
		requests[i-firstIP].join();
	}
	handler.join();
	return 0;
}
