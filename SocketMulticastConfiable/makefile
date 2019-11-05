all: emitter receiver

DatagramPacket.o: DatagramPacket.cpp
	g++ -c DatagramPacket.cpp -Wall -std=c++11

DatagramSocket.o: DatagramSocket.cpp
	g++ -c DatagramSocket.cpp -Wall -std=c++11

MulticastSocket.o: MulticastSocket.cpp
	g++ -c MulticastSocket.cpp -Wall -std=c++11

emitter: DatagramPacket.o DatagramSocket.o MulticastSocket.o emitter.cpp
	g++ DatagramPacket.o DatagramSocket.o MulticastSocket.o emitter.cpp -o emitter -std=c++11

receiver: DatagramPacket.o DatagramSocket.o MulticastSocket.o receiver.cpp
	g++ DatagramPacket.o DatagramSocket.o MulticastSocket.o receiver.cpp -o receiver -std=c++11

.PHONY: clean

clean:
	rm -rf *.o *.exe emitter receiver