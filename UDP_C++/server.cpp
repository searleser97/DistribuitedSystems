#include <iostream>
#include <string>
#include "DatagramSocket.h"

using namespace std;

int main(int argc, char* argv[]) {
	uint16_t puerto;
	cout << "Puerto en el que se va a escuchar: ";
	cin >> puerto;
	DatagramSocket servidor(puerto);
	cout << "Servidor iniciado...\n";
	while(1){
		int nums[2];
		DatagramPacket solicitud((char*)nums, sizeof(nums));
		servidor.receive(solicitud);
		cout << "Solicitud enviada desde el cliente " << solicitud.getAddress() << ":" << solicitud.getPort() << " con los numeros " << nums[0] << ", " << nums[1] << "\n";
		int suma = nums[0] + nums[1];
		DatagramPacket respuesta((char*)&suma, sizeof(suma), solicitud.getAddress(), solicitud.getPort());
		servidor.send(respuesta);
	}
	return 0;
}
