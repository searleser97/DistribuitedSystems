#include <bits/stdc++.h>
using namespace std;
#include "MulticastSocket.h"
int main() {
  string ipmulti;
  char str[100];
  int port, ttl;
  cin >> ipmulti >> port >> ttl >> str;
  MulticastSocket ms;
  DatagramPacket packet(str, strlen(str), ipmulti, port);
  ms.send(packet, ttl);
}