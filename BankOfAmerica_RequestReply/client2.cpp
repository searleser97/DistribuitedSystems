#include "Request.h"
#include <chrono>
#include <iostream>
#include <random>
#include <string>

std::mt19937_64
    seed2(std::chrono::steady_clock::now().time_since_epoch().count());
int random2(int min, int max) { // [min, max]
  return std::uniform_int_distribution<int>(min, max)(seed2);
}

using namespace std;

int main(int argc, char *argv[]) {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);
  string ip;
  uint16_t puerto;
  int nums[1];
  int n;
  //   cout << "Direccion IP del servidor: ";
  cin >> ip;
  //   cout << "Puerto del servidor: ";
  cin >> puerto;
  //   cout << "Numero de solicitudes: ";
  cin >> n;
  Request r;
  size_t len_reply;
  int suma =
      *(int *)r.doOperation(ip, puerto, Message::allowedOperations::getBalance,
                            NULL, 0, len_reply);
  for (int i = 0; i < n; i++) {
    suma += nums[0] = random2(1, 9);
    try {
      int balance = *(int *)r.doOperation(
          ip, puerto, Message::allowedOperations::transfer, (char *)nums,
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
