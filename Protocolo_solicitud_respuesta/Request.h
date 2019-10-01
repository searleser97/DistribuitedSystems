#include "SocketDatagrama.h"

class Request {
    public:
        Request();
        char * doOperation(char *IP, int port, Code::allowedOperations operation, char *arguments);
};