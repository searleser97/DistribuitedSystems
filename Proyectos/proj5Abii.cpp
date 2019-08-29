#include <bits/stdc++.h>
using namespace std;

class Fraccion {
private:
  int numerador;
  int denominador;

public:
  Fraccion(int n, int d);
  double division();
  void minimaExpresion();
  int getNumerador();
  int getDenominador();
};

Fraccion::Fraccion(int n, int d) : numerador(n), denominador(d) {}
double Fraccion::division() { return (double)numerador / denominador; }
void Fraccion::minimaExpresion() {
  int g = __gcd(numerador, denominador);
  numerador /= g;
  denominador /= g;
}
int Fraccion::getNumerador() {
  return numerador;
}
int Fraccion::getDenominador() {
  return denominador;
}
int main() {
  Fraccion f1(18, 15);
  Fraccion f2(1, 5);

  cout << "Division: " << f1.division() << endl;

  f1.minimaExpresion();
  cout << "Minima expresion: " << f1.getNumerador() << "/" << f1.getDenominador() << endl; 
}
