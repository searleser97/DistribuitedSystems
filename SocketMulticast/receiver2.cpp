#include <bits/stdc++.h>
using namespace std;
#include "MulticastSocket.h"
int main() {
  try {
    string ipmulti;
    int nums[2];
    int port, ttl;
    cin >> ipmulti >> port;
    MulticastSocket ms(port);
    ms.joinGroup(0, ipmulti);
    DatagramPacket packet((char *)nums, sizeof(nums));
    ms.receiveTimeout(packet, 3, 0);
    int res = nums[0] + nums[1];
    cout << packet.getAddress() << ":" << packet.getPort() << " => " << nums[0]
         << " + " << nums[1] << " = " << res << endl;
    DatagramPacket packet2((char *)&res, sizeof(res), packet.getAddress(), packet.getPort());
    ms.send(packet2, ttl);
  } catch (string msg) {
    cout << msg << endl;
  }
}