#include <bits/stdc++.h>
using namespace std;
#include "MulticastSocket.h"
mt19937_64 seed(chrono::steady_clock::now().time_since_epoch().count());

int random(int min, int max) { // [min, max]
  return uniform_int_distribution<int>(min, max)(seed);
}

int main() {
  string ipmulti;
  int cant_depositos;
  int datos[2];
  int port, ttl;
  cin >> ipmulti >> port >> ttl >> cant_depositos;
  MulticastSocket ms;
  for (int i = 0; i < cant_depositos; i++) {
    try {
      int cantidad = random(1, 9);
      datos[0] = random(0, numeric_limits<int>::max());
      datos[1] = cantidad;
      DatagramPacket packet((char *)datos, sizeof(datos), ipmulti, port);
      ms.sendReliable(packet, ttl, 3);
    } catch (string msg) {
      std::cerr << msg << endl;
      exit(0);
    }
  }
  return 0;
}