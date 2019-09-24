#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <strings.h>
#include "PaqueteDatagrama.h"

PaqueteDatagrama::PaqueteDatagrama(const char * datos, unsigned int longitud, const char * ip, int puerto): longitud(longitud) {
	this->inicializaPuerto(puerto);
	this->inicializaIp(ip);
	this->inicializaDatos(datos);
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int longitud): longitud(longitud) {
	this->inicializaPuerto(0);
	this->inicializaIp("127.0.0.1");
	this->inicializaDatos();
}

PaqueteDatagrama::~PaqueteDatagrama() {
	delete this->datos;
}

void PaqueteDatagrama::inicializaPuerto(int puerto) {
	this->puerto = htons(puerto);
}

void PaqueteDatagrama::inicializaIp(const char *ip) {
	strcpy(this->ip, ip);
}

void PaqueteDatagrama::inicializaDatos(const char *datos) {
	this->datos = new char[longitud];
	memcpy(this->datos, datos, longitud);
}

void PaqueteDatagrama::inicializaDatos() {
	this->datos = new char[longitud];
}

char * PaqueteDatagrama::obtieneDireccion() {
	return this->ip;
}

char * PaqueteDatagrama::obtieneDatos() {
	return this->datos;
}

unsigned int PaqueteDatagrama::obtieneLongitud() {
	return this->longitud;
}

int PaqueteDatagrama::obtienePuerto() {
	return ntohs(this->puerto);
}
