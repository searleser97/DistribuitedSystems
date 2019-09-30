all: main

gfx.o: gfx.c
	gcc -c gfx.c -Wall

util.o: util.cpp
	g++ -c util.cpp -std=c++11 -Wall

main: gfx.o util.o main.o
	g++ gfx.o util.o main.cpp -o main -std=c++11 -lX11 -Wall

.PHONY: clean

clean:
	rm -rf *.o *.exe