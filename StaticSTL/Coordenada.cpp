#include "Coordenada.h"
#include "cmath"

Coordenada::Coordenada(double xx, double yy) {
    // xx = radio, yy = angulo
    // x = xx * cos(yy);
    // y = xx * sin(yy);
    x = xx;
    y = yy;
}
// Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy) {}

double Coordenada::obtenerX() { return x; }

double Coordenada::obtenerY() { return y; }

