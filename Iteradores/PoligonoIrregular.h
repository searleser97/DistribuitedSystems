#include "Coordenada.h"
#include <vector>
using namespace std;

class PoligonoIrregular {
private:
  vector<Coordenada> vertices;
  static int verticesNumber;

public:
  PoligonoIrregular();

  PoligonoIrregular(vector<Coordenada> vertices);

  void anadeVertice(Coordenada vertice);

  void imprimeVertices();

  static void imprimeNumeroDeVertices();
  void ordenaA();
};