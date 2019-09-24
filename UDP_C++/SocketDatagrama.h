#include <netinet/in.h>
#include "PaqueteDatagrama.h"
class SocketDatagrama {
public:
	SocketDatagrama();
	SocketDatagrama(int);
	~SocketDatagrama();
	
	int recibe(PaqueteDatagrama &p);
	
	int envia(PaqueteDatagrama &p);

private:
	struct sockaddr_in direccionLocal;
	struct sockaddr_in direccionForanea;
	int s; //ID socket
};
