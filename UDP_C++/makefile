all: client server

DatagramPacket.o: DatagramPacket.cpp
	g++ -c DatagramPacket.cpp -Wall

DatagramSocket.o: DatagramSocket.cpp
	g++ -c DatagramSocket.cpp -Wall

client: DatagramPacket.o DatagramSocket.o
	g++ DatagramPacket.o DatagramSocket.o client.cpp -o client

server: DatagramPacket.o DatagramSocket.o
	g++ DatagramPacket.o DatagramSocket.o server.cpp -o server

.PHONY: clean

clean:
	rm -rf *.o *.exe client server