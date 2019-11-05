#include "MulticastSocket.h"
#include "DatagramSocket.h"
#include <arpa/inet.h>
#include <string.h>
#include <iostream>

MulticastSocket::MulticastSocket() : DatagramSocket() {}

MulticastSocket::MulticastSocket(uint16_t iport) : DatagramSocket(iport) {}

MulticastSocket::~MulticastSocket() {}

void MulticastSocket::joinGroup(uint16_t iport, const std::string &addr) {
	memset(&groupAddr, 0, sizeof(groupAddr));
	groupAddr.imr_multiaddr.s_addr = inet_addr(addr.c_str());
	groupAddr.imr_interface.s_addr = htons(iport);
	if (setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *)&groupAddr, sizeof(groupAddr)) < 0) {
		throw std::string("Could not join group: ") + std::string(strerror(errno));
	}
}

void MulticastSocket::leaveGroup(uint16_t iport, const std::string &addr) {
	memset(&groupAddr, 0, sizeof(groupAddr));
	groupAddr.imr_multiaddr.s_addr = inet_addr(addr.c_str());
	groupAddr.imr_interface.s_addr = htons(iport);
	if (setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, (void *)&groupAddr, sizeof(groupAddr)) < 0) {
		throw std::string("Could not leave group") + std::string(strerror(errno));
	}
}

int MulticastSocket::send(DatagramPacket &p, uint8_t ttl) {
	setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *)&ttl, sizeof(ttl));
	return DatagramSocket::send(p);
}

int MulticastSocket::receive(DatagramPacket &p) {
	return DatagramSocket::receive(p);
}

int MulticastSocket::receiveTimeout(DatagramPacket &p, time_t seconds, suseconds_t microseconds) {
	return DatagramSocket::receiveTimeout(p, seconds, microseconds);
}

int MulticastSocket::receiveReliable(DatagramPacket &p, time_t seconds, suseconds_t microseconds) {
	try {
		auto ans = DatagramSocket::receiveTimeout(p, seconds, microseconds);
		char res = 1;
		DatagramPacket dp(&res, 1, p.getAddress(), p.getPort());
		DatagramSocket::send(dp);
		return ans;
	} catch (std::string msg) {
		throw msg;
	}
}

int MulticastSocket::sendReliable(DatagramPacket &p, uint8_t ttl, uint32_t n_receivers) {
	setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *)&ttl, sizeof(ttl));
	for (uint32_t i = 0; i < 7; ++i) {
		int ans = DatagramSocket::send(p);
		uint32_t n_received = 0;
		for (uint32_t j = 0; j < n_receivers; j++) {
			try {
				DatagramPacket dp(new char[1], 1);
				DatagramSocket::receiveTimeout(dp, 3, 0);
				if (!dp.getData()[0]) {
					std::cerr << "Negative ack received from #" << j+1 << "\n";
				} else{
					n_received++;
				}
			} catch (std::string msg) {
				std::cerr << "Did not receive ack from #" << j+1 << ": " << msg << "\n";
			}
		}
		if (n_received == n_receivers) {
			return ans;
		}
	}
	throw std::string("All attempts failed");
}