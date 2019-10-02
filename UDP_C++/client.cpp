#include <iostream>
#include <string>
#include "DatagramSocket.h"

using namespace std;

int main(int argc, char* argv[]) {
	string ip;
	uint16_t puerto;
	int nums[2], suma;
	cout << "Direccion IP del servidor: ";
	cin >> ip;
	cout << "Puerto del servidor: ";
	cin >> puerto;
	cout << "Numeros a sumar: ";
	cin >> nums[0] >> nums[1];

	DatagramSocket cliente;
	DatagramPacket solicitud((char*)nums, sizeof(nums), ip, puerto);
	cliente.send(solicitud);

	cout << "Numeros enviados.\n";
	
	DatagramPacket respuesta((char*)&suma, sizeof(suma));
	cliente.receive(respuesta);
	cout << "Respuesta desde " << respuesta.getAddress() << ":" << respuesta.getPort() << ": " << suma << "\n";
	
	return 0;
}
