#include "Request.h"
#include <chrono>
#include <random>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Util.h"

char* Request::doOperation(const std::string addr, uint16_t iport, Message::AllowedOperations operation, char *arguments, size_t len, size_t & len_reply) {
	Message *msg = new Message();
	msg->type = Message::Type::request;
	msg->requestId = Util::random(0, std::numeric_limits<uint64_t>::max());
	msg->operation = operation;
	memcpy(msg->arguments, arguments, len);
	msg->length = len;

	DatagramPacket pq((char*)msg, sizeof(Message), addr, iport);
	DatagramSocket sock;

	Message *msg2 = new Message();
	DatagramPacket pqresp((char*)msg2, sizeof(Message));
	int i;
	for (i = 0; i < 7; i++) {
		try {
			sock.send(pq);
			sock.receiveTimeout(pqresp, 3, 0);
			break;
		} catch(const char* msg) {
			std::cerr << msg << '\n';
		}
	}
	if(i == 7) {
		len_reply = 0;
		throw "All attempts failed, server not available";
	}
	len_reply = msg2->length;
	return msg2->arguments;
}

Request::Request() {}
