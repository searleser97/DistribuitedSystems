#ifndef DatagramSocket_H_
#define DatagramSocket_H_
#include <cstddef>
#include <string>
#include "DatagramPacket.h"

class MulticastSocket {
  public:
    MulticastSocket(uint16_t iport);
    ~MulticastSocket();
    void joinGroup(uint16_t iport, const std::string & addr);
    void leaveGroup(uint16_t iport, const std::string & addr);
    int send(DatagramPacket &p, uint8_t TTL);
		int receive(DatagramPacket &p);
		int receiveTimeout(DatagramPacket & p, time_t seconds, suseconds_t microseconds);
};
#endif
