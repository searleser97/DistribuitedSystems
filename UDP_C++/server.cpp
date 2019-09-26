#include <iostream>
#include <string>
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"

using namespace std;


int main(int argc, char* argv[])
{
	int puerto;
	cout << "Puerto en el que se va a escuchar: ";
	cin >> puerto;
	SocketDatagrama s(puerto);
	cout << "Servidor iniciado...\n";
	while(1){
		PaqueteDatagrama p(1000);
		s.recibe(p);
		string msj(p.obtieneDatos());
		cout << "Solicitud enviada desde el cliente " << p.obtieneDireccion() << ":" << p.obtienePuerto() << " con el texto " << msj << "\n";
		msj += " ECO";
		PaqueteDatagrama respuesta(msj.c_str(), msj.size(), p.obtieneDireccion(), p.obtienePuerto());
		s.envia(respuesta);
	}
	return 0;
}