all: client server web_server

DatagramPacket.o: src/DatagramPacket.cpp
	g++ -c src/DatagramPacket.cpp -Wall

DatagramSocket.o: src/DatagramSocket.cpp
	g++ -c src/DatagramSocket.cpp -Wall

Request.o: src/Request.cpp
	g++ -c src/Request.cpp -Wall

Reply.o: src/Reply.cpp
	g++ -c src/Reply.cpp -Wall

Util.o: src/Util.cpp
	g++ -c src/Util.cpp -Wall

ImagePacket.o: src/ImagePacket.cpp
	g++ -c src/ImagePacket.cpp -Wall

Image.o: src/Image.cpp
	g++ -c src/Image.cpp -Wall

client: Util.o Image.o ImagePacket.o DatagramPacket.o DatagramSocket.o Request.o Reply.o
	g++ Util.o Image.o ImagePacket.o DatagramPacket.o DatagramSocket.o Request.o Reply.o client.cpp -o client -lpthread

server: Util.o Image.o ImagePacket.o DatagramPacket.o DatagramSocket.o Request.o Reply.o
	g++ Util.o Image.o ImagePacket.o DatagramPacket.o DatagramSocket.o Request.o Reply.o server.cpp -o server -lpthread

mongoose.o: mongoose.c
	g++ -c mongoose.c -Wall

web_server: mongoose.o
	g++ mongoose.o web_server.cpp

.PHONY: clean

clean:
	rm -rf *.o *.exe server client
