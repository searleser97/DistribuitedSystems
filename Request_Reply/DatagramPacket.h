#include <cstddef>
#include <string>

#ifndef DatagramPacket_H_
#define DatagramPacket_H_

class DatagramPacket {
	public:
		DatagramPacket(char* const buf, size_t len);
		DatagramPacket(char* const buf, size_t len, const std::string & addr, uint16_t iport);
		std::string getAddress();
		char *getData();
		size_t getLength();
		uint16_t getPort();
		void setAddress(const std::string & addr);
		void setData(char* const buf, size_t len);
		void setLength(size_t len);
		void setPort(uint16_t iport);

	private:
		char *buffer;
		uint16_t port;
		std::string address;
		size_t length;
};

#endif
