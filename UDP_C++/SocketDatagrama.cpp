#include "SocketDatagrama.h"
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <strings.h>
#include <string>
#include <sstream>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

uint32_t ipBlock(uint32_t x, int pos) { return (x >> (pos * 8)) & 0xFF; }

string printIp(uint32_t ip) {
	stringstream ss;
	ss << ipBlock(ip, 0) << "." << ipBlock(ip, 1) << "." << ipBlock(ip, 2) << "." << ipBlock(ip, 3);
 	return ss.str();
}

SocketDatagrama::SocketDatagrama(int puerto)
{
	s = socket(AF_INET, SOCK_DGRAM, 0);

	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port = htons(puerto);
	bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
	//len = sizeof(msg_to_client_addr);
}
SocketDatagrama::~SocketDatagrama()
{
	close(s);
}

int SocketDatagrama::recibe(PaqueteDatagrama &p)
{
	socklen_t sssize = sizeof(direccionForanea);
	int ans = recvfrom(s, p.obtieneDatos(), sizeof(char) * p.obtieneLongitud(), 0, (struct sockaddr*) &direccionForanea, &sssize);
	p.inicializaPuerto(ntohs(direccionForanea.sin_port));
	p.inicializaIp(printIp(direccionForanea.sin_addr.s_addr).c_str());
	return ans;
}

int SocketDatagrama::envia(PaqueteDatagrama &p)
{
	int sssize = sizeof(direccionForanea);;
	int ans = sendto(s, p.obtieneDatos(), sizeof(char) * p.obtieneLongitud(), 0,  (struct sockaddr*) &direccionForanea, sssize);
	return ans;
}


