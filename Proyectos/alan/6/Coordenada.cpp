#include "Coordenada.h"

Coordenada::Coordenada(): x(0), y(0), z(0) {}

Coordenada::Coordenada(double x, double y, double z): x(x), y(y), z(z) {}

double Coordenada::getX() {
	return x;
}

double Coordenada::getY() {
	return y;
}

double Coordenada::getZ() {
	return z;
}
