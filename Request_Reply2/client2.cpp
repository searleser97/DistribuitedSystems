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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  string ip;
  uint16_t puerto;
  int nums[2];
  int n;
//   cout << "Direccion IP del servidor: ";
  cin >> ip;
//   cout << "Puerto del servidor: ";
  cin >> puerto;
//   cout << "Numero de solicitudes: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    Request r;
    size_t len_reply;
    nums[0] = random2(-100, 100);
    nums[1] = random2(-100, 100);
    try {
      int *suma =
          (int *)r.doOperation(ip, puerto, Message::allowedOperations::sum,
                               (char *)nums, sizeof(nums), len_reply);
    //   cout << "Respuesta desde el servidor con longitud " << len_reply << ": "
    //        << *suma << "\n";
    } catch (const char *msg) {
      std::cerr << msg << endl;
      return -1;
    }
  }
  return 0;
}

/*
16   con impresion 20s con 100 pacquetes
16   sin impresion 1s
4000 con impresion 200s
4000 sin impresion 100s
*/