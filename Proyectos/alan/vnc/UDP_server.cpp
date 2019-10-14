#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <vector>
#include <fstream>
#include <map>
#include <thread>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "DatagramPacket.h"
#include "DatagramSocket.h"
#include "Message.h"
#include "Info.h"
#include "Part.h"

const uint16_t port = 15645;

using namespace std;

size_t GetFileSize(string filename) {
	struct stat stat_buf;
	int rc = stat(filename.c_str(), &stat_buf);
	return rc == 0 ? stat_buf.st_size : -1;
}

void erase(string filename) {
	remove(filename.c_str());
}

map<string, ifstream> files;

void send_info(DatagramSocket & server, string ip, uint16_t port, string filename) {
	size_t size = GetFileSize("/tmp/" + filename);
	files[filename].open("/tmp/" + filename, ios::binary);
	Message *msg = new Message();
	msg->action = 1;
	Info *info = new Info();
	strcpy(info->name, filename.c_str());
	info->size = size;
	memcpy(msg->data, info, sizeof(Info));
	DatagramPacket p((char*)msg, sizeof(Message), ip, port);
	server.send(p);
	delete info;
	delete msg;
}

void send_part(DatagramSocket & server, string ip, uint16_t port, Part *part) {
	auto & file = files[string(part->name)];
	file.seekg(part->offset);
	file.read(part->data, part->size);
	Message *msg = new Message();
	msg->action = 3;
	memcpy(msg->data, part, sizeof(Part));
	DatagramPacket p((char*)msg, sizeof(Message), ip, port);
	server.send(p);
	delete msg;
}

int main() {
	DatagramSocket server(port);
	Message *msg = new Message();
	while(true) {
		DatagramPacket p((char*)msg, sizeof(Message));
		server.receive(p);
		string client_ip = p.getAddress();
		uint16_t client_port = p.getPort();
		if (msg->action == 0) {
			int q;
			memcpy(&q, msg->data, sizeof(int));
			time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
			string filename = string(ctime(&now));
			filename = filename.substr(0, filename.size() - 1) + ".png";
			string cmd = "scrot -q " + to_string(q) + " '/tmp/" + filename + "'";
			cout << client_ip << ":" << client_port << " " << cmd << "\n";
			system(cmd.c_str());
			send_info(server, client_ip, client_port, filename);
		} else if(msg->action == 2) {
			Part *part = new Part();
			memcpy(part, msg->data, sizeof(Part));
			send_part(server, client_ip, client_port, part);
			delete part;
		} else if(msg->action == 4) {
			Info *info = new Info();
			memcpy(info, msg->data, sizeof(Info));
			string name(info->name);
			files[name].close();
			erase("/tmp/" + name);
			files.erase(name);
			delete info;
		}
	}
	return 0;
}
