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
#include <vector>

class Rectangulo {
private:
  Coordenada cercaOrigen;
  Coordenada lejosOrigen;

public:
  Rectangulo();
  Rectangulo(Coordenada, Coordenada);

  void imprimeEsq();
  vector<Coordenada> esquinas();
  double obtieneArea();
};

// -------------------------------------------------------------------

#include <iostream>
using namespace std;

Rectangulo::Rectangulo(Coordenada co, Coordenada lo)
    : cercaOrigen(co), lejosOrigen(lo) {}

void Rectangulo::imprimeEsq() {

  cout << "Para la esquina superior izquierda.\n";

  cout << "(" << cercaOrigen.obtenerX() << ", ";
  cout << cercaOrigen.obtenerY() << ", ";
  cout << cercaOrigen.obtenerZ() << ")" << endl;

  cout << "(" << lejosOrigen.obtenerX() << ", ";
  cout << lejosOrigen.obtenerY() << ", ";
  cout << lejosOrigen.obtenerZ() << ")" << endl;
}

vector<Coordenada> Rectangulo::esquinas() {
  // return {cercaOrigen, lejosOrigen};
}

double Rectangulo::obtieneArea() {
  double a = abs(lejosOrigen.obtenerX() - cercaOrigen.obtenerX());
  double b = abs(lejosOrigen.obtenerY() - cercaOrigen.obtenerY());
  double c = abs(lejosOrigen.obtenerZ() - cercaOrigen.obtenerZ());
  return a * b + a * c + b * c;
}
// -------------------------------------------------------------------

#include <set>

bool cmp(Coordenada &a, Coordenada &b) {
  if (a.obtenerX() < b.obtenerX())
    return true;
  else if (a.obtenerX() > b.obtenerX())
    return false;
  if (a.obtenerY() < b.obtenerY())
    return true;
  else if (a.obtenerY() > b.obtenerY())
    return false;
  if (a.obtenerZ() < b.obtenerZ())
    return true;
  return false;
}

class Ortoedro {
private:
  // [0]: front, [1]: right, [2]: back, [3]: left
  // [4]: up, [5]: bottom;
  vector<Rectangulo> rectangulos;

public:
  Ortoedro();
  Ortoedro(Coordenada, Coordenada);
  set<Coordenada, decltype(cmp)> obtieneVertices();
  double obtieneArea();
  double obtieneVolumen();
};

// -------------------------------------------------------------------
Ortoedro::Ortoedro(Coordenada co, Coordenada lo) {
  rectangulos.resize(6);
  double coX = co.obtenerX();
  double coY = co.obtenerY();
  double coZ = co.obtenerZ();
  double loX = lo.obtenerX();
  double loY = lo.obtenerY();
  double loZ = lo.obtenerZ();
  rectangulos[0] =
      Rectangulo(Coordenada(coX, coY, coZ), Coordenada(loX, coY, loZ));
  rectangulos[1] =
      Rectangulo(Coordenada(coX, loY, coZ), Coordenada(loX, loY, loZ));
  rectangulos[2] =
      Rectangulo(Coordenada(coX, coY, coZ), Coordenada(coX, loY, loZ));
  rectangulos[3] =
      Rectangulo(Coordenada(loX, coY, coZ), Coordenada(loX, loY, loZ));
  rectangulos[4] =
      Rectangulo(Coordenada(coX, coY, loZ), Coordenada(loX, loY, loZ));
  rectangulos[5] =
      Rectangulo(Coordenada(coX, coY, coZ), Coordenada(loX, loY, coZ));
}

set<Coordenada, decltype(cmp)> Ortoedro::obtieneVertices() {
  set<Coordenada, decltype(cmp)> s(cmp);
  for (auto &rec : rectangulos) {
    for (auto &esq : rec.esquinas()) {
      s.insert(esq);
    }
  }
  return s;
}

double Ortoedro::obtieneArea() {
  double ans = 0;
  for (auto &rec : rectangulos) {
    ans += rec.obtieneArea();
  }
  return ans;
}

double Ortoedro::obtieneVolumen() {
  double bottomArea = rectangulos[5].obtieneArea();
  vector<Coordenada> esquinas = rectangulos[0].esquinas();
	return bottomArea * (abs(esquinas[1].obtenerZ() - esquinas[0].obtenerZ()));
}

int main() {
	double a, b, c, d, e, f;
	cout << "Introduce las 3 coordenadas de la esquina cerca del origen: ";
	cin >> a >> b >> c;
	cout << "Introduce las 3 coordenadas de la esquina lejos del origen: ";
	cin >> d >> e >> f;
	Ortoedro o(Coordenada(a, b, c), Coordenada(d, e, f));
	cout << "Vertices:" << endl;
	for (Coordenada v : o.obtieneVertices()) {
		cout << "(" << v.obtenerX() << ", " << v.obtenerY() << ", " << v.obtenerZ() << ")" << endl;
	}
	cout << "Area: " << o.obtieneArea() << endl;
	cout << "Volumen: " << o.obtieneVolumen() << endl;
	return 0;
}