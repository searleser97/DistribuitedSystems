#include <cstddef>
#include <string>
#include <netinet/in.h>
#include "DatagramPacket.h"

#ifndef DatagramSocket_H_
#define DatagramSocket_H_

class DatagramSocket {
	public:
		DatagramSocket();
		DatagramSocket(uint16_t iport);
		DatagramSocket(uint16_t iport, const std::string & addr);
		~DatagramSocket();
		void unbind();
		int send(DatagramPacket &p);
		int receive(DatagramPacket &p);
		int receiveTimeout(DatagramPacket & p, time_t seconds, suseconds_t microseconds);

	private:
		struct sockaddr_in localAddress;
		struct sockaddr_in remoteAddress;
		int s;
		struct timeval timeout;
};

#endif
