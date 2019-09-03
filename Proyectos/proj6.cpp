class Coordenada {
private:
  double x;

  double y;

public:
  Coordenada(double = 0, double = 0);

  double obtenerX();

  double obtenerY();
};

// -------------------------------------------------------------------

#include <cmath>

Coordenada::Coordenada(double xx, double yy) {
  // xx = radio, yy = angulo
  x = xx * cos(yy);
  y = xx * sin(yy);
}
// Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy) {}

double Coordenada::obtenerX() { return x; }

double Coordenada::obtenerY() { return y; }

// -------------------------------------------------------------------

class Rectangulo {
private:
  Coordenada superiorIzq;

  Coordenada inferiorDer;

public:
  Rectangulo();

  Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
  Rectangulo(Coordenada supIzq, Coordenada infDer);

  void imprimeEsq();

  Coordenada obtieneSupIzq();

  Coordenada obtieneInfDer();

  double obtieneArea();
};

// -------------------------------------------------------------------

#include <iostream>
using namespace std;

Rectangulo::Rectangulo() : superiorIzq(0, 0), inferiorDer(0, 0) {}

Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer,
                       double yInfDer)
    : superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer) {}

Rectangulo::Rectangulo(Coordenada supIzq, Coordenada infDer) {
  superiorIzq = supIzq;
  inferiorDer = infDer;
}

void Rectangulo::imprimeEsq() {

  cout << "Para la esquina superior izquierda.\n";

  cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY()
       << endl;

  cout << "Para la esquina inferior derecha.\n";

  cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY()
       << endl;
}

Coordenada Rectangulo::obtieneSupIzq() { return superiorIzq; }

Coordenada Rectangulo::obtieneInfDer() { return inferiorDer; }

double Rectangulo::obtieneArea() {
  double alto = obtieneSupIzq().obtenerY() - obtieneInfDer().obtenerY();
  double ancho = obtieneInfDer().obtenerX() - obtieneSupIzq().obtenerX();
  return alto * ancho;
}

// -------------------------------------------------------------------

#include <vector>

class Ortoedro {
private:
  Coordenada superior;

  Coordenada inferior;

public:
  Ortoedro();

  Ortoedro(Coordenada superior, Coordenada inferior);

  vector<Coordenada> obtieneVertices();

  double obtieneArea();

  double obtieneVolumen();
};

// -------------------------------------------------------------------

Ortoedro::Ortoedro() {}

int main() { return 0; }