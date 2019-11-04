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
  int port, ttl;
  cin >> ipmulti >> port >> ttl >> cant_depositos;
  MulticastSocket ms;
  for (int i = 0; i < cant_depositos; i++) {
    try {
      int ac = random(1, 9);
      DatagramPacket packet((char *)&ac, sizeof(ac), ipmulti, port);
      ms.sendReliable(packet, ttl, 3);
    } catch (string msg) {
      std::cerr << msg << endl;
    }
  }
}