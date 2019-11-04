#include <bits/stdc++.h>
using namespace std;
#include "MulticastSocket.h"
int main() {
  unordered_map<string, int> nbd;
  string ipmulti;
  int monto;
  int port, ttl;
  cin >> ipmulti >> port;

  try {
    MulticastSocket ms(port);
    ms.joinGroup(0, ipmulti);
    while (true) {
      DatagramPacket packet((char *) &monto, sizeof(monto));
      ms.receiveReliable(packet, 3600, 0);
      nbd[packet.getAddress()] += monto;
      cout << packet.getAddress() << ":" << packet.getPort();
      cout << "monto recibido: " << monto << endl;
      cout << "monto acumulado: " << nbd[packet.getAddress()] << endl;
    }
  } catch (string msg) {
    cout << msg << endl;
  }
}