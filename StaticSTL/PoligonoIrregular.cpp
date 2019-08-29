#include "PoligonoIrregular.h"
#include <iostream>
using namespace std;

int PoligonoIrregular::verticesNumber = 0;

PoligonoIrregular::PoligonoIrregular() {
    // vertices.reserve(10000);
    verticesNumber += 0;
}

PoligonoIrregular::PoligonoIrregular(vector<Coordenada> v) {
    verticesNumber += v.size();
    vertices = v;
}

void PoligonoIrregular::imprimeVertices() {
    for (auto vertice : vertices) {
        cout << "(" << vertice.obtenerX() << ", " << vertice.obtenerY() << ")" << endl;
    }
}

void PoligonoIrregular::anadeVertice(Coordenada vertice) {
    verticesNumber++;
    vertices.push_back(vertice);
}

void PoligonoIrregular::imprimeNumeroDeVertices() {
    cout << verticesNumber << endl;
}