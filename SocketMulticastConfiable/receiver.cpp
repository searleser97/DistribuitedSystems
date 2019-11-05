#include <bits/stdc++.h>
using namespace std;
#include "MulticastSocket.h"
int main() {
  map<string, int> nbd;
  set<pair<string, uint64_t>> visited;
  string ipmulti;
  uint64_t datos[2];
  int port, ttl;
  cin >> ipmulti >> port;

  try {
    MulticastSocket ms(port);
    ms.joinGroup(0, ipmulti);
    while (true) {
      DatagramPacket packet((char *) &datos, sizeof(datos));
      ms.receiveReliable(packet, 3600, 0);
      uint64_t id = datos[0];
      uint64_t monto = datos[1];
      if(!visited.count({packet.getAddress(), id})){
        nbd[packet.getAddress()] += monto;
        visited.insert({packet.getAddress(), id});
        cout << packet.getAddress() << ":" << packet.getPort() << endl;
        cout << "monto recibido: " << monto << endl;
        cout << "monto acumulado: " << nbd[packet.getAddress()] << endl << endl;
      }
    }
  } catch (string msg) {
    cout << msg << endl;
  }
  return 0;
}