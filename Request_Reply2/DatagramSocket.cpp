#include "DatagramSocket.h"
#include <netinet/in.h>
#include <strings.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

DatagramSocket::DatagramSocket(): DatagramSocket(0) {}

DatagramSocket::DatagramSocket(uint16_t iport): DatagramSocket(iport, "0.0.0.0") {}

DatagramSocket::DatagramSocket(uint16_t iport, const std::string & addr) {
	s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	bzero((char *)&localAddress, sizeof(localAddress));
	localAddress.sin_family = AF_INET;
	localAddress.sin_addr.s_addr = inet_addr(addr.c_str());
	localAddress.sin_port = htons(iport);
	bind(s, (struct sockaddr *)&localAddress, sizeof(localAddress));
}

DatagramSocket::~DatagramSocket() {
	unbind();
}

void DatagramSocket::unbind() {
	close(s);
	s = 0;
}

int DatagramSocket::receive(DatagramPacket &p) {
	socklen_t len = sizeof(remoteAddress);
	int n = recvfrom(s, p.getData(), p.getLength(), 0, (struct sockaddr*)&remoteAddress, &len);
	p.setPort(ntohs(remoteAddress.sin_port));
	p.setAddress(std::string(inet_ntoa(remoteAddress.sin_addr)));
	p.setLength(n);
	return n;
}

int DatagramSocket::receiveTimeout(DatagramPacket & p, time_t seconds, suseconds_t microseconds) {
	timeout.tv_sec = seconds;
	timeout.tv_usec = microseconds;	
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

	socklen_t len = sizeof(remoteAddress);

	int n = recvfrom(s, p.getData(), p.getLength(), 0, (struct sockaddr*)&remoteAddress, &len);

	if (n < 0) {
		if (errno == EWOULDBLOCK)
			throw "Timeout while receiving the packet";
		else
			throw "Error while receiving the packet";
	}

	p.setPort(ntohs(remoteAddress.sin_port));
	p.setAddress(std::string(inet_ntoa(remoteAddress.sin_addr)));
	p.setLength(n);
	return n;
}

int DatagramSocket::send(DatagramPacket &p) {
	bzero((char *)&remoteAddress, sizeof(remoteAddress));
	remoteAddress.sin_family = AF_INET;
	remoteAddress.sin_port = htons(p.getPort());
	remoteAddress.sin_addr.s_addr = inet_addr(p.getAddress().c_str());
	return sendto(s, p.getData(), p.getLength(), 0, (struct sockaddr*)&remoteAddress, sizeof(remoteAddress));
}
