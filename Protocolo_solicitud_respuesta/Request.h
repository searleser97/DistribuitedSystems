#ifndef REQUEST_H
#define REQUEST_H
#include "SocketDatagrama.h"
#include "Message.h"

class Request {
    public:
        Request();
        char * doOperation(char *IP, int port, Code::allowedOperations operation, char *arguments);
};
#endif