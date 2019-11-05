#ifndef DatagramSocket_H_
#define DatagramSocket_H_
#include <cstddef>
#include <string>
#include <netinet/in.h>
#include <sys/time.h>
#include "DatagramPacket.h"

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

	protected:
		struct sockaddr_in localAddress;
		struct sockaddr_in remoteAddress;
		int s;
		struct timeval timeout;
};

#endif
