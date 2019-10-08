#include "DatagramSocket.h"
#include "Message.h"
#include <map>
#include <utility>

#ifndef REPLY_H
#define REPLY_H

class Reply {
	public:
		Reply(int iport);
		Message *getRequest();
		void sendReply(const char *arguments, size_t len);
		std::string address;
		uint16_t port;
		uint64_t requestId;
	private:
		DatagramSocket *localSocket;
		std::map<std::pair<std::string, uint64_t>, std::pair<const char*, size_t>> history;
		Message::allowedOperations operation;
};

#endif
