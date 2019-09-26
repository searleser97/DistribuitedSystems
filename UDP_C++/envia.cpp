#include <iostream>
#include <string>
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"

using namespace std;


int main(int argc, char* argv[])
{
	string ip;
	int puerto;
	int nums[2], suma;
	cout << "Direccion IP del servidor: ";
	cin >> ip;
	cout << "Puerto del servidor: ";
	cin >> puerto;
	cout << "Numeros a sumar: ";
	cin >> nums[0] >> nums[1];

	PaqueteDatagrama paquete((char*)nums, sizeof(nums), ip.c_str(), puerto);
	SocketDatagrama s(puerto);
	s.envia(paquete);

	cout << "Numeros enviados.\n";
	
	PaqueteDatagrama respuesta(1000);
	s.recibe(respuesta);
	suma = *respuesta.obtieneDatos();
	cout << "Respuesta desde " << respuesta.obtieneDireccion() << ":" << respuesta.obtienePuerto() << ": " << suma << "\n";
	
	return 0;
}
