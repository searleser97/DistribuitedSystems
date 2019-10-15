#include "Request.h"
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include "Util.h"

using namespace std;

void receiveImage() {
  
}

void writeFile() {

}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  string ip;
  uint16_t puerto;
  int nums[1];
  int n;
  cout << "Direccion IP del servidor: ";
  cin >> ip;
  cout << "Puerto del servidor: ";
  cin >> puerto;
  cout << "Numero de solicitudes: ";
  cin >> n;
  Request r;
  size_t len_reply;
  int suma = *(int *)r.doOperation(
      ip, puerto, Message::AllowedOperations::getBalance, NULL, 0, len_reply);
  for (int i = 0; i < n; i++) {
    suma += nums[0] = Util::random(1, 9);
    try {
      int balance = *(int *)r.doOperation(
          ip, puerto, Message::AllowedOperations::transfer, (char *)nums,
          sizeof(nums), len_reply);
      cout << "Respuesta desde el servidor con longitud " << len_reply << ": "
           << balance << "\n";
      if (suma != balance) {
        std::cerr << "Inconsistent data between client and server" << endl;
        std::cerr << "expected: " << suma << endl;
        std::cerr << "got: " << balance << endl;
        return -1;
      }
    } catch (const char *msg) {
      std::cerr << msg << endl;
      return -1;
    }
  }
  return 0;
}
