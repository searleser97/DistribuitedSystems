#include "Response.h"
#include "Message.h"
#include <iostream>

using namespace std;

int main()
{

    int puerto;
	cout << "Puerto en el que se va a escuchar: ";
	cin >> puerto;
    Respuesta *response = new Respuesta(puerto);
	cout << "Servidor iniciado...\n";


	while(1){
		Message *msg = response->getRequest();
        cout << "Solicitud de " << response->IP << ":" << response->port << "\n";
        if (msg->operationId == Code::allowedOperations::suma) {
            int *nums = (int*)msg->arguments;
            int sum = nums[0] + nums[1];
            response->sendReply((char*)&sum);
        }
	}
    return 0;
}