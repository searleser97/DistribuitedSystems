all: client server

DatagramPacket.o: DatagramPacket.cpp
	g++ -c DatagramPacket.cpp -Wall

DatagramSocket.o: DatagramSocket.cpp
	g++ -c DatagramSocket.cpp -Wall

Request.o: Request.cpp
	g++ -c Request.cpp -Wall

Reply.o: Reply.cpp
	g++ -c Reply.cpp -Wall

Util.o: Util.cpp
	g++ -c Util.cpp -Wall

ImagePacket.o: ImagePacket.cpp
	g++ -c ImagePacket.cpp -Wall

client: Util.o ImagePacket.o DatagramPacket.o DatagramSocket.o Request.o Reply.o
	g++ Util.o ImagePacket.o DatagramPacket.o DatagramSocket.o Request.o Reply.o client.cpp -o client -lpthread

server: Util.o ImagePacket.o DatagramPacket.o DatagramSocket.o Request.o Reply.o
	g++ Util.o ImagePacket.o DatagramPacket.o DatagramSocket.o Request.o Reply.o server.cpp -o server -lpthread

.PHONY: clean

clean:
	rm -rf *.o *.exe server client