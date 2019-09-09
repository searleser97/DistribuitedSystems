#include <vector>
#include "Rectangulo.h"
using namespace std;

#ifndef Ortoedro_H_
#define Ortoedro_H_

class Ortoedro {
	private:
		Coordenada lowerLeft;
		Coordenada upperRight;
		Rectangulo bottom;
		Rectangulo top;
		Rectangulo left;
		Rectangulo right;
		Rectangulo front;
		Rectangulo back;
	public:
		Ortoedro();
		Ortoedro(Coordenada lowerLeft, Coordenada upperRight);
		vector<Coordenada> obtieneVertices();
		double obtieneArea();
		double obtieneVolumen();
};

#endif
