#include "Coordenada.h"

#ifndef Rectangulo_H_
#define Rectangulo_H_

class Rectangulo {
	private:
		Coordenada lowerLeft;
		Coordenada upperRight;
	public:
		Rectangulo();
		Rectangulo(Coordenada lowerLeft, Coordenada upperRight);
		Coordenada getLowerLeft();
		Coordenada getUpperRight();
		double obtieneArea();
};

#endif
