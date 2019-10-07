#include <iostream>
#include <string>
#include "Request.h"
#include <chrono>
#include <random>

std::mt19937_64
	seed2(std::chrono::steady_clock::now().time_since_epoch().count());
int random2(int min, int max) { // [min, max]
  return std::uniform_int_distribution<int>(min, max)(seed2);
}


using namespace std;

int main(int argc, char* argv[]) {
	string ip;
	uint16_t puerto;
	int nums[2];
    int n;
	cout << "Direccion IP del servidor: ";
	cin >> ip;
	cout << "Puerto del servidor: ";
	cin >> puerto;
	cout << "Numero de solicitudes: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        Request r;
        size_t len_reply;
        nums[0] = random2(-100, 100);
        nums[1] = random2(-100, 100);

        int *suma = (int*)r.doOperation(ip, puerto, Message::allowedOperations::sum, (char*)nums, sizeof(nums), len_reply); 
        cout << "Respuesta desde el servidor con longitud " << len_reply << ": " << *suma << "\n";
    }
	return 0;
}
