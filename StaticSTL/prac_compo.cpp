#include <iostream>
using namespace std;

int random(int min, int max) { return min + rand() % (max - min + 1); }

#include "PoligonoIrregular.h"

int main() {
  rand();
  PoligonoIrregular pi({Coordenada(5, 8), Coordenada(2, 4)});
  pi.anadeVertice(Coordenada(-2, -4));
  pi.imprimeVertices();

  vector<PoligonoIrregular> v;
  int n = 1000, m = 5000;
  for (int i = 0; i < n; i++) {
    int verticesNumber = random(m, m);
    PoligonoIrregular poligono;
    for (int j = 0; j < verticesNumber; j++) {
      poligono.anadeVertice(Coordenada(random(-10, 10), random(-10, 10)));
    }
    v.push_back(poligono);
  }

  PoligonoIrregular::imprimeNumeroDeVertices();
  return 0;
}
