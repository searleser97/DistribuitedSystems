all: client2 server gen

DatagramPacket.o: DatagramPacket.cpp
	g++ -c DatagramPacket.cpp -Wall

DatagramSocket.o: DatagramSocket.cpp
	g++ -c DatagramSocket.cpp -Wall

Request.o: Request.cpp
	g++ -c Request.cpp -Wall

Reply.o: Reply.cpp
	g++ -c Reply.cpp -Wall

gen: gen.cpp
	g++ gen.cpp -O2 -o gen -Wall

client2: DatagramPacket.o DatagramSocket.o Request.o Reply.o client2.cpp
	g++ DatagramPacket.o DatagramSocket.o Request.o Reply.o client2.cpp -o client2

server: DatagramPacket.o DatagramSocket.o Request.o Reply.o server.cpp
	g++ DatagramPacket.o DatagramSocket.o Request.o Reply.o server.cpp -o server

.PHONY: clean

clean:
	rm -rf *.o *.exe server client2 gen