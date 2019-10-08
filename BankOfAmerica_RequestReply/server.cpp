#include <iostream>
#include <string>
#include "Reply.h"
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[]) {
	uint16_t puerto;
	cout << "Puerto en el que se va a escuchar: ";
	cin >> puerto;
	Reply reply(puerto);
	cout << "Servidor iniciado...\n";
	unordered_map<string, int> nbd;
	while(1){
		Message *msg = reply.getRequest();
		int* nums = (int*)msg->arguments;
		// cout << "Solicitud enviada desde el cliente " << reply.address << ":" << reply.port << "\n";
		// cout << " requestId=" << msg->requestId << "\n";
		// cout << " operationId=" << msg->operationId << "\n";
		// cout << " sizeof(args)=" << msg->length << "\n";
		if (msg->operationId == Message::allowedOperations::sum) {
			// cout << " Numeros a sumar: " << nums[0] << " y " << nums[1] << "\n";
			int suma = nums[0] + nums[1];
			reply.sendReply((char*)&suma, sizeof(suma));
		} else if (msg->operationId == Message::allowedOperations::transfer) {
			nbd[reply.address] += nums[0];
			reply.sendReply((char*)&nbd[reply.address], sizeof(int));
		} else if (msg->operationId == Message::allowedOperations::getBalance) {
			reply.sendReply((char*)&nbd[reply.address], sizeof(int));
		}
		// cout << "\n";
	}
	return 0;
}
