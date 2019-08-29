#include "Coordenada.h"

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