#include "../UDP_C++/SocketDatagrama.h"

class Request {
    public:
        Request();
        char * doOperation(char *IP, int port, int operationId, char *arguments);
    private:
        SocketDatagrama *socketlocal;
};