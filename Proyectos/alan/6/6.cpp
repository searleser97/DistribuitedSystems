#include <iostream>
#include <iomanip>
#include "Ortoedro.h"
using namespace std;

int main() {
	double a, b, c, d, e, f;
	cout << "Introduce las 3 coordenadas de la esquina inferior izquierda: ";
	cin >> a >> b >> c;
	cout << "Introduce las 3 coordenadas de la esquina superior derecha: ";
	cin >> d >> e >> f;
	Ortoedro o(Coordenada(a, b, c), Coordenada(d, e, f));
	cout << "Vertices:\n";
	for (Coordenada v : o.obtieneVertices()) {
		cout << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")\n";
	}
	cout << "Area: " << o.obtieneArea() << "\n";
	cout << "Volumen: " << o.obtieneVolumen() << "\n";
	return 0;
}
