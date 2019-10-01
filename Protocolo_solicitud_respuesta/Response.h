#ifndef RESPONSE_H
#define RESPONSE_H
#include "SocketDatagrama.h"
#include "Message.h"

class Respuesta {
    public:
        Respuesta(int pl);
        Message *getRequest(void);
        void sendReply(const char *respuesta);
        char *IP;
        int port;
    private:
        SocketDatagrama *socketlocal;
        Code::allowedOperations operation;
        unsigned int requestId;
};

#endif