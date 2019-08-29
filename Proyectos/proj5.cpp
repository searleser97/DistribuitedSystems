#include <bits/stdc++.h>
using namespace std;

typedef __int128_t lli;
lli gcd(lli a, lli b) { return !b ? a : gcd(b, a % b); }

class Fraccion {
private:
  int num;
  int den;

public:
  Fraccion(int num, int den);
  double toDouble();
  void imprimir();
  Fraccion reduce();
};

Fraccion::Fraccion(int num, int den) {
  this->num = num;
  this->den = den;
}

double Fraccion::toDouble() { return (double)num / den; }

Fraccion Fraccion::reduce() {
  lli g = gcd(num, den);
  return Fraccion(num / g, den / g);
}

void Fraccion::imprimir() { cout << num << " / " << den << endl; }

int main() { 
  Fraccion f1(10, 6), f2(200, 100);
  f1.reduce().imprimir();
  f2.reduce().imprimir();
  cout << f1.toDouble() << endl;
  cout << f2.toDouble() << endl;
  return 0;
}