all: main

gfx.o: gfx.c
	gcc -c gfx.c -Wall

util.o: util.cpp
	g++ -c util.cpp -std=c++11 -Wall

point.o: point.cpp
	g++ -c point.cpp -std=c++11 -Wall

color.o: color.cpp
	g++ -c color.cpp -std=c++11 -Wall

worm.o: worm.cpp
	g++ -c worm.cpp -std=c++11 -Wall

main: gfx.o util.o point.o color.o worm.o main.o
	g++ gfx.o util.o point.o color.o worm.o main.cpp -o main -std=c++11 -lX11 -Wall

.PHONY: clean

clean:
	rm -rf *.o *.exe