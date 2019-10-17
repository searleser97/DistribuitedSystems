#include <bits/stdc++.h>
using namespace std;
#include "MulticastSocket.h"
int main() {
  try {
  string ipmulti;
  char str[100];
  int port, ttl;
  cin >> ipmulti >> port >> ttl >> str;
  MulticastSocket ms;
  DatagramPacket packet(str, strlen(str) + 1, ipmulti, port);
  ms.send(packet, ttl);
  } catch (string msg) {
    cout << msg << endl;
  }
}