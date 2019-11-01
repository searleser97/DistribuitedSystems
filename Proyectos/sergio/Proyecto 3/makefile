all: client server rest_api

DatagramPacket.o: src/DatagramPacket.cpp
	g++ -std=c++17 -c src/DatagramPacket.cpp -Wall

DatagramSocket.o: src/DatagramSocket.cpp
	g++ -std=c++17 -c src/DatagramSocket.cpp -Wall

Request.o: src/Request.cpp
	g++ -std=c++17 -c src/Request.cpp -Wall

Reply.o: src/Reply.cpp
	g++ -std=c++17 -c src/Reply.cpp -Wall

Util.o: src/Util.cpp
	g++ -std=c++17 -c src/Util.cpp -Wall

ImagePacket.o: src/ImagePacket.cpp
	g++ -std=c++17 -c src/ImagePacket.cpp -Wall

Image.o: src/Image.cpp
	g++ -std=c++17 -c src/Image.cpp -Wall

client: Util.o Image.o ImagePacket.o DatagramPacket.o DatagramSocket.o Request.o Reply.o
	g++ -std=c++17 Util.o Image.o ImagePacket.o DatagramPacket.o DatagramSocket.o Request.o Reply.o client.cpp -o client -lpthread

server: Util.o Image.o ImagePacket.o DatagramPacket.o DatagramSocket.o Request.o Reply.o
	g++ -std=c++17 Util.o Image.o ImagePacket.o DatagramPacket.o DatagramSocket.o Request.o Reply.o server.cpp -o server -lpthread

mongoose.o: mongoose.c
	g++ -std=c++17 -c mongoose.c -Wall

rest_api: mongoose.o
	g++ -std=c++17 mongoose.o rest_api.cpp -o rest_api

.PHONY: clean

clean:
	rm -rf *.o *.exe server client
