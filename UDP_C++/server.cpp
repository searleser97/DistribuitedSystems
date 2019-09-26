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
		int *nums = (int*)p.obtieneDatos();
		cout << "Solicitud enviada desde el cliente " << p.obtieneDireccion() << ":" << p.obtienePuerto() << " con los numeros " << nums[0] << ", " << nums[1] << "\n";
		int suma = nums[0] + nums[1];
		PaqueteDatagrama respuesta((char*)&suma, sizeof(suma), p.obtieneDireccion(), p.obtienePuerto());
		s.envia(respuesta);
	}
	return 0;
}
