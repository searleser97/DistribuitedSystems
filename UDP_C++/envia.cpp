#include <iostream>
#include <string>
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"

using namespace std;


int main(int argc, char* argv[])
{
	string ip;
	int puerto;
	string mensaje;
	cout << "Direccion IP del servidor: ";
	cin >> ip;
	cout << "Puerto del servidor: ";
	cin >> puerto;
	cout << "Mensaje a enviar: ";
	cin >> mensaje;

	PaqueteDatagrama paquete(mensaje.c_str(), mensaje.size(), ip.c_str(), puerto);
	SocketDatagrama s(puerto);
	s.envia(paquete);
	
	PaqueteDatagrama respuesta(1000);
	s.recibe(respuesta);
	cout << "Respuesta desde " << respuesta.obtieneDireccion() << ":" << respuesta.obtienePuerto() << ": " << respuesta.obtieneDatos() << "\n";
	
	return 0;
}
