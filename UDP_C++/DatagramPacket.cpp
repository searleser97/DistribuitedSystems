#include "DatagramPacket.h"

DatagramPacket::DatagramPacket(char* const buf, size_t len): port(0), address("") {
	setData(buf, len);
}

DatagramPacket::DatagramPacket(char* const buf, size_t len, const std::string & addr, uint16_t iport) {
	setData(buf, len);
	setAddress(addr);
	setPort(iport);
}

std::string DatagramPacket::getAddress() {
	return address;
}

uint16_t DatagramPacket::getPort() {
	return port;
}

char* DatagramPacket::getData() {
	return buffer;
}

size_t DatagramPacket::getLength() {
	return length;
}

void DatagramPacket::setAddress(const std::string & addr) {
	address = addr;
}

void DatagramPacket::setPort(uint16_t iport) {
	port = iport;
}

void DatagramPacket::setLength(size_t len) {
	length = len;
}

void DatagramPacket::setData(char* const buf, size_t len) {
	buffer = buf;
	setLength(len);
}
