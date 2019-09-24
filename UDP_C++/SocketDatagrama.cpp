#include "SocketDatagrama.h"
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <strings.h>
#include <string>
#include <sstream>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

SocketDatagrama::SocketDatagrama()
{
	s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
}

SocketDatagrama::SocketDatagrama(int puerto)
{
	s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = htonl(INADDR_ANY);
	direccionLocal.sin_port = htons(puerto);
	bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
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
	p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
	return ans;
}

int SocketDatagrama::envia(PaqueteDatagrama &p)
{
	int sssize = sizeof(direccionForanea);
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	direccionForanea.sin_family = AF_INET;
	direccionForanea.sin_port = htons(p.obtienePuerto());
	inet_pton(AF_INET, p.obtieneDireccion(), &direccionForanea.sin_addr);
	int ans = sendto(s, p.obtieneDatos(), sizeof(char) * p.obtieneLongitud(), 0,  (struct sockaddr*) &direccionForanea, sssize);
	return ans;
}


