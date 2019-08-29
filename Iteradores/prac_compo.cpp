#include <iostream>
using namespace std;

double random(int min, int max) {
  if (min == max)
    return min;
  double aux = (double)(rand() % ((max - min + 1) * 1000));
  return (aux / 1000.0) - max;
}

// double random(double min, double max) { return min + rand() % (max - min +
// 1); }

#include "PoligonoIrregular.h"

int main() {
  srand(time(0));
  PoligonoIrregular pi({Coordenada(random(-100, 100), random(-100, 100)),
                        Coordenada(random(-100, 100), random(-100, 100))});

  int verticesNumber = 10;
  for (int j = 0; j < verticesNumber; j++) {
    pi.anadeVertice(Coordenada(random(-100, 100), random(-100, 100)));
  }
  pi.imprimeVertices();
  return 0;
}
