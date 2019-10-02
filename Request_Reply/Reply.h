#include "DatagramSocket.h"
#include "Message.h"

#ifndef REPLY_H
#define REPLY_H

class Reply {
	public:
		Reply(int iport);
		Message *getRequest();
		void sendReply(const char *arguments, size_t len);
		std::string address;
		uint16_t port;
		unsigned int requestId;
	private:
		DatagramSocket *localSocket;
		Message::allowedOperations operation;
};

#endif
