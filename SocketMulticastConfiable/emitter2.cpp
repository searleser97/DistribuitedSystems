#include <bits/stdc++.h>
using namespace std;
#include "MulticastSocket.h"
int main() {
  try {
    string ipmulti;
    int nums[2];
    int port, ttl;
    cin >> ipmulti >> port >> ttl >> nums[0] >> nums[1];
    MulticastSocket ms;
    DatagramPacket packet((char *)nums, sizeof(nums), ipmulti, port);
    ms.send(packet, ttl);
    int res;
    DatagramPacket packet2((char *)&res, sizeof(res));
    while (true) {
      ms.receiveTimeout(packet2, 3, 0);
      cout << packet2.getAddress() << ":" << packet2.getPort() << " = "
           << (int)*packet2.getData() << endl;
    }
  } catch (string msg) {
    cout << msg << endl;
  }
}