#include "../UDP_C++/SocketDatagrama.h"

class Respuesta {
    public:
        Respuesta(int pl);
        struct mensaje *getRequest(void);
        void sendReply(char *respuesta);
    private:
        SocketDatagrama *socketlocal;
};