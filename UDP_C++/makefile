all: envia server

PaqueteDatagrama.o: PaqueteDatagrama.cpp
	g++ -c PaqueteDatagrama.cpp -Wall

SocketDatagrama.o: SocketDatagrama.cpp
	g++ -c SocketDatagrama.cpp -Wall

envia: PaqueteDatagrama.o SocketDatagrama.o
	g++ PaqueteDatagrama.o SocketDatagrama.o envia.cpp -o envia

server: PaqueteDatagrama.o SocketDatagrama.o
	g++ PaqueteDatagrama.o SocketDatagrama.o server.cpp -o server

.PHONY: clean

clean:
	rm -rf *.o *.exe