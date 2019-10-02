#include <iostream>
#include <string>
#include "Request.h"

using namespace std;

int main(int argc, char* argv[]) {
	string ip;
	uint16_t puerto;
	int nums[2];
	cout << "Direccion IP del servidor: ";
	cin >> ip;
	cout << "Puerto del servidor: ";
	cin >> puerto;
	cout << "Numeros a sumar: ";
	cin >> nums[0] >> nums[1];

	Request r;
	size_t len_reply;
	int *suma = (int*)r.doOperation(ip, puerto, Message::allowedOperations::sum, (char*)nums, sizeof(nums), len_reply);
	
	cout << "Respuesta desde el servidor con longitud " << len_reply << ": " << *suma << "\n";
	
	return 0;
}
