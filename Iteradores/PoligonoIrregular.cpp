#include "PoligonoIrregular.h"
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int PoligonoIrregular::verticesNumber = 0;

PoligonoIrregular::PoligonoIrregular() {
  vertices.reserve(10000);
  verticesNumber += 0;
}

PoligonoIrregular::PoligonoIrregular(vector<Coordenada> v) {
  verticesNumber += v.size();
  vertices = v;
}

void PoligonoIrregular::imprimeVertices() {
  // for (auto vertice : vertices) {
  //     cout << "(" << vertice.obtenerX() << ", " << vertice.obtenerY() << ")"
  //     << endl;
  // }
  ordenaA();

  for (vector<Coordenada>::iterator i = vertices.begin(); i != vertices.end();
       i++) {
    cout << fixed << setprecision(3);
    cout << "(" << i->obtenerX() << ", " << i->obtenerY() << ")";
    cout << " " << hypot(i->obtenerX(), i->obtenerY()) << endl;
  }
}

void PoligonoIrregular::anadeVertice(Coordenada vertice) {
  verticesNumber++;
  vertices.push_back(vertice);
}

void PoligonoIrregular::imprimeNumeroDeVertices() {
  cout << verticesNumber << endl;
}

void PoligonoIrregular::ordenaA() {
  sort(vertices.begin(), vertices.end(), [](Coordenada &a, Coordenada &b) {
    return hypot(a.obtenerX(), a.obtenerY()) <
           hypot(b.obtenerX(), b.obtenerY());
  });
}