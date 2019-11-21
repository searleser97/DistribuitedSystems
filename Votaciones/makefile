all: client2 server gen serverTime

DatagramPacket.o: DatagramPacket.cpp
	g++ -c DatagramPacket.cpp -Wall

DatagramSocket.o: DatagramSocket.cpp
	g++ -c DatagramSocket.cpp -Wall

Request.o: Request.cpp
	g++ -c Request.cpp -Wall

Reply.o: Reply.cpp
	g++ -c Reply.cpp -Wall
Trie.o: Trie.cpp
	g++ -c Trie.cpp -Wall
gen: gen.cpp
	g++ gen.cpp -O2 -o gen -Wall

client2: DatagramPacket.o DatagramSocket.o Request.o Reply.o client2.cpp
	g++ DatagramPacket.o DatagramSocket.o Request.o Reply.o client2.cpp -o client2 -lpthread

server: DatagramPacket.o DatagramSocket.o Request.o Reply.o Trie.o server.cpp
	g++ DatagramPacket.o DatagramSocket.o Request.o Reply.o server.cpp -o server Trie.o

serverTime: serverTime.cpp Request.o Reply.o DatagramPacket.o DatagramSocket.o
	g++ DatagramPacket.o DatagramSocket.o Request.o Reply.o serverTime.cpp -o serverTime -Wall

.PHONY: clean

clean:
	rm -rf *.o *.exe server client2 gen Trie.o serverTime