all: emitter receiver emitter2 receiver2

DatagramPacket.o: DatagramPacket.cpp
	g++ -c DatagramPacket.cpp -Wall

DatagramSocket.o: DatagramSocket.cpp
	g++ -c DatagramSocket.cpp -Wall

MulticastSocket.o: MulticastSocket.cpp
	g++ -c MulticastSocket.cpp -Wall

emitter: DatagramPacket.o DatagramSocket.o MulticastSocket.o emitter.cpp
	g++ DatagramPacket.o DatagramSocket.o MulticastSocket.o emitter.cpp -o emitter -g

receiver: DatagramPacket.o DatagramSocket.o MulticastSocket.o receiver.cpp
	g++ DatagramPacket.o DatagramSocket.o MulticastSocket.o receiver.cpp -o receiver -g

emitter2: DatagramPacket.o DatagramSocket.o MulticastSocket.o emitter2.cpp
	g++ DatagramPacket.o DatagramSocket.o MulticastSocket.o emitter2.cpp -o emitter2 -g

receiver2: DatagramPacket.o DatagramSocket.o MulticastSocket.o receiver2.cpp
	g++ DatagramPacket.o DatagramSocket.o MulticastSocket.o receiver2.cpp -o receiver2 -g

.PHONY: clean

clean:
	rm -rf *.o *.exe emitter receiver