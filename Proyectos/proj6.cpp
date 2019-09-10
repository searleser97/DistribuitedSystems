class Coordenada {
private:
  double x;
  double y;
  double z;
public:
  Coordenada(double = 0, double = 0, double = 0);
  double obtenerX();
  double obtenerY();
  double obtenerZ();
};

// -------------------------------------------------------------------

#include <cmath>
Coordenada::Coordenada(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {}

double Coordenada::obtenerX() { return x; }
double Coordenada::obtenerY() { return y; }
double Coordenada::obtenerZ() { return z; }

// -------------------------------------------------------------------

class Rectangulo {
private:
  Coordenada cercaOrigen;
  Coordenada lejosOrigen;
public:
  Rectangulo();
  Rectangulo(Coordenada, Coordenada);

  void imprimeEsq();

  double obtieneArea();
};

// -------------------------------------------------------------------

#include <iostream>
using namespace std;

Rectangulo::Rectangulo(Coordenada co, Coordenada lo)  : cercaOrigen(co), lejosOrigen(lo) {}

void Rectangulo::imprimeEsq() {

  cout << "Para la esquina superior izquierda.\n";

  cout << "(" << cercaOrigen.obtenerX() << ", ";
  cout << cercaOrigen.obtenerY() << ", ";
  cout << cercaOrigen.obtenerZ() << ")" << endl;

  cout << "(" << lejosOrigen.obtenerX() << ", ";
  cout << lejosOrigen.obtenerY() << ", ";
  cout << lejosOrigen.obtenerZ() << ")" << endl;
}

double Rectangulo::obtieneArea() {
  
  return 0.0;
}
// -------------------------------------------------------------------

#include <vector>

class Ortoedro {
private:
  vector<Rectangulo> rectangulos;
public:
  Ortoedro();
  vector<Coordenada> obtieneVertices();
  double obtieneArea();
  double obtieneVolumen();
};

// -------------------------------------------------------------------

Ortoedro::Ortoedro() {}

int main() { return 0; }