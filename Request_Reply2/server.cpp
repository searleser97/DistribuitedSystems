#include <iostream>
#include <string>
#include "Reply.h"

using namespace std;

int main(int argc, char* argv[]) {
	uint16_t puerto;
	cout << "Puerto en el que se va a escuchar: ";
	cin >> puerto;
	Reply r(puerto);
	cout << "Servidor iniciado...\n";
	while(1){
		Message *msg = r.getRequest();
		int* nums = (int*)msg->arguments;
		cout << "Solicitud enviada desde el cliente " << r.address << ":" << r.port << "\n";
		cout << " requestId=" << msg->requestId << "\n";
		cout << " operationId=" << msg->operationId << "\n";
		cout << " sizeof(args)=" << msg->length << "\n";
		if (msg->operationId == Message::allowedOperations::sum) {
			cout << " Numeros a sumar: " << nums[0] << " y " << nums[1] << "\n";
			int suma = nums[0] + nums[1];
			r.sendReply((char*)&suma, sizeof(suma));
		}
		cout << "\n";
	}
	return 0;
}
