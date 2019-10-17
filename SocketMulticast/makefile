all: emitter receiver

DatagramPacket.o: DatagramPacket.cpp
	g++ -c DatagramPacket.cpp -Wall

DatagramSocket.o: DatagramSocket.cpp
	g++ -c DatagramSocket.cpp -Wall

MulticastSocket.o: MulticastSocket.cpp
	g++ -c MulticastSocket.cpp -Wall

emitter: DatagramPacket.o DatagramSocket.o MulticastSocket.o
	g++ DatagramPacket.o DatagramSocket.o MulticastSocket.o emitter.cpp -o emitter

receiver: DatagramPacket.o DatagramSocket.o MulticastSocket.o
	g++ DatagramPacket.o DatagramSocket.o MulticastSocket.o receiver.cpp -o receiver

.PHONY: clean

clean:
	rm -rf *.o *.exe emitter receiver