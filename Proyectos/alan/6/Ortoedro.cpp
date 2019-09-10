#include "Ortoedro.h"
#include <cmath>

Ortoedro::Ortoedro(): lowerLeft(), upperRight() {}

Ortoedro::Ortoedro(Coordenada lowerLeft, Coordenada upperRight): lowerLeft(lowerLeft), upperRight(upperRight) {
	double a = lowerLeft.getX();
	double b = lowerLeft.getY();
	double c = lowerLeft.getZ();
	double d = upperRight.getX();
	double e = upperRight.getY();
	double f = upperRight.getZ();
	bottom = Rectangulo(Coordenada(a, b, c), Coordenada(d, b, f));
	top = Rectangulo(Coordenada(a, e, c), Coordenada(d, e, f));
	left = Rectangulo(Coordenada(a, b, c), Coordenada(a, e, f));
	right = Rectangulo(Coordenada(d, b, c), Coordenada(d, e, f));
	front = Rectangulo(Coordenada(a, b, f), Coordenada(d, e, f));
	back = Rectangulo(Coordenada(a, b, c), Coordenada(d, e, c));
}

vector<Coordenada> Ortoedro::obtieneVertices() {
	double a = lowerLeft.getX();
	double b = lowerLeft.getY();
	double c = lowerLeft.getZ();
	double d = upperRight.getX();
	double e = upperRight.getY();
	double f = upperRight.getZ();
	vector<Coordenada> ans;
	ans.emplace_back(a, b, c);
	ans.emplace_back(a, b, f);
	ans.emplace_back(d, b, f);
	ans.emplace_back(d, b, c);
	ans.emplace_back(a, e, c);
	ans.emplace_back(a, e, f);
	ans.emplace_back(d, e, f);
	ans.emplace_back(d, e, c);
	return ans;
}

double Ortoedro::obtieneArea() {
	return bottom.obtieneArea() + top.obtieneArea() + left.obtieneArea() + right.obtieneArea() + front.obtieneArea() + back.obtieneArea();
}

double Ortoedro::obtieneVolumen() {
	double a = abs(upperRight.getX() - lowerLeft.getX());
	double b = abs(upperRight.getY() - lowerLeft.getY());
	double c = abs(upperRight.getZ() - lowerLeft.getZ());
	return a*b*c;
}
