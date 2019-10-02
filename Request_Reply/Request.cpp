#include "Request.h"
#include <chrono>
#include <random>
#include <stdlib.h>
#include <string.h>

std::mt19937_64
	seed(std::chrono::steady_clock::now().time_since_epoch().count());
int random(int min, int max) { // [min, max]
  return std::uniform_int_distribution<int>(min, max)(seed);
}

char* Request::doOperation(const std::string addr, uint16_t iport, Message::allowedOperations operation, char *arguments, size_t len, size_t & len_reply) {
	Message *msg = new Message();
	msg->messageType = Message::kindMessages::request;
	msg->requestId = random(1, 1 << 30);
	msg->operationId = operation;
	memcpy(msg->arguments, arguments, len);
	msg->length = len;

	DatagramPacket pq((char*)msg, sizeof(Message), addr, iport);
	DatagramSocket sock;
	sock.send(pq);

	Message *msg2 = new Message();
	DatagramPacket pqresp((char*)msg2, sizeof(Message));
	sock.receive(pqresp);
	len_reply = msg2->length;
	return msg2->arguments;
}

Request::Request() {}
