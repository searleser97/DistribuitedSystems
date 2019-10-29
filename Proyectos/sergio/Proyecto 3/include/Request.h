#include "DatagramSocket.h"
#include "Message.h"

#ifndef REQUEST_H
#define REQUEST_H

class Request {
    public:
        Request();
        static char* doOperation(const std::string &addr, uint16_t iport, Message::AllowedOperations operation, char *arguments, size_t len, size_t & len_reply);
};
#endif
