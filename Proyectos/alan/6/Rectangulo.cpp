#include "Rectangulo.h"
#include <cmath>

Rectangulo::Rectangulo(): lowerLeft(), upperRight() {}

Rectangulo::Rectangulo(Coordenada lowerLeft, Coordenada upperRight): lowerLeft(lowerLeft), upperRight(upperRight) {}

Coordenada Rectangulo::getLowerLeft() {
	return lowerLeft;
}

Coordenada Rectangulo::getUpperRight() {
	return upperRight;
}

double Rectangulo::obtieneArea() {
	double a = abs(upperRight.getX() - lowerLeft.getX());
	double b = abs(upperRight.getY() - lowerLeft.getY());
	double c = abs(upperRight.getZ() - lowerLeft.getZ());
	return a*b + a*c + b*c;
}
