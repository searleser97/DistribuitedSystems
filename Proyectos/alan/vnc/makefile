all: UDP_client UDP_server web_server

DatagramPacket.o: DatagramPacket.cpp DatagramPacket.h
	g++ -c DatagramPacket.cpp -Wall -std=c++11

DatagramSocket.o: DatagramSocket.cpp DatagramSocket.h
	g++ -c DatagramSocket.cpp -Wall -std=c++11

UDP_client: DatagramPacket.o DatagramSocket.o UDP_client.cpp Message.h Part.h Info.h
	g++ DatagramPacket.o DatagramSocket.o UDP_client.cpp -o UDP_client -Wall -std=c++11 -lpthread

UDP_server: DatagramPacket.o DatagramSocket.o UDP_server.cpp Message.h Part.h Info.h
	g++ DatagramPacket.o DatagramSocket.o UDP_server.cpp -o UDP_server -Wall -std=c++11 -lpthread

web_server: web_server.cpp mongoose.c
	g++ web_server.cpp mongoose.c -o web_server -Wall -std=c++11

.PHONY: clean

clean:
	rm -rf *.o *.exe UDP_client UDP_server web_server