#include "MulticastSocket.h"
#include "DatagramSocket.h"
#include <arpa/inet.h>
#include <string.h>

MulticastSocket::MulticastSocket() : DatagramSocket() {}

MulticastSocket::MulticastSocket(uint16_t iport) : DatagramSocket(iport) {}

MulticastSocket::~MulticastSocket() {}

void MulticastSocket::joinGroup(uint16_t iport, const std::string &addr) {
  memset(&groupAddr, 0, sizeof(groupAddr));
  groupAddr.imr_multiaddr.s_addr = inet_addr(addr.c_str());
  groupAddr.imr_interface.s_addr = htons(iport);
  if (setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *)&groupAddr,
                 sizeof(groupAddr)) < 0)
    throw std::string("Could not join group: ") + std::string(strerror(errno));
}

void MulticastSocket::leaveGroup(uint16_t iport, const std::string &addr) {
  memset(&groupAddr, 0, sizeof(groupAddr));
  groupAddr.imr_multiaddr.s_addr = inet_addr(addr.c_str());
  groupAddr.imr_interface.s_addr = htons(iport);
  if (setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, (void *)&groupAddr,
                 sizeof(groupAddr)) < 0)
    throw std::string("Could not leave group") + std::string(strerror(errno));
}

int MulticastSocket::send(DatagramPacket &p, uint8_t ttl) {
  setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *)&ttl, sizeof(ttl));
  return DatagramSocket::send(p);
}

int MulticastSocket::receive(DatagramPacket &p) {
  return DatagramSocket::receive(p);
}

int MulticastSocket::receiveTimeout(DatagramPacket &p, time_t seconds,
                                    suseconds_t microseconds) {
  return DatagramSocket::receiveTimeout(p, seconds, microseconds);
}

int MulticastSocket::receiveReliable(DatagramPacket &p, time_t seconds,
                                     suseconds_t microseconds) {
  try {
    auto ans = DatagramSocket::receiveTimeout(p, seconds, microseconds);
		return ans;
  } catch (std::string msg) {
		char ack = 0;
		auto dp = DatagramPacket(&ack, sizeof(char));
		DatagramSocket::send(dp);
	}

}

int MulticastSocket::sendReliable(DatagramPacket &p, uint8_t ttl,
                                  uint32_t n_receivers) {
  setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *)&ttl, sizeof(ttl));
  auto ans = DatagramSocket::send(p);
  for (int i = 0; i < n_receivers; i++) {
    DatagramPacket dp(new char[1], 1);
    try {
      DatagramSocket::receiveTimeout(dp, 3, 0);
      if (!dp.getData()[0]) {
        throw std::string("Negative ack received");
      }
    } catch (std::string msg) {
      throw std::string("Did not receive ack");
    }
  }
  return ans;
}