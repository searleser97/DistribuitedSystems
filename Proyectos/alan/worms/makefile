all: animacion

gfx.o: gfx.c
	gcc -c gfx.c -Wall

animacion.o: animacion.cpp
	g++ -c animacion.cpp -std=c++11 -Wall

point.o: point.cpp
	g++ -c point.cpp -std=c++11 -Wall

curve.o: curve.cpp
	g++ -c curve.cpp -std=c++11 -Wall

worm.o: worm.cpp
	g++ -c worm.cpp -std=c++11 -Wall

animacion: gfx.o animacion.o point.o curve.o worm.o
	g++ gfx.o animacion.o point.o curve.o worm.o -o animacion -std=c++11 -lX11 -Wall

.PHONY: clean

clean:
	rm -rf *.o *.exe