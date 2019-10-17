#include <bits/stdc++.h>
using namespace std;
#include "MulticastSocket.h"
int main() {
  try {
    string ipmulti;
    char str[100];
    int port, ttl;
    cin >> ipmulti >> port;
    MulticastSocket ms(port);
    ms.joinGroup(0, ipmulti);
    DatagramPacket packet(str, sizeof(str));
    ms.receiveTimeout(packet, 3, 0);
    cout << packet.getAddress() << endl;
    cout << packet.getPort() << endl;
    cout << packet.getLength() << endl;
    cout << str << endl;
  } catch (string msg) {
    cout << msg << endl;
  }
}