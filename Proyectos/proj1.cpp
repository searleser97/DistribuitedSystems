#include <cmath>
#include <iostream>
using namespace std;

double epsilon = 1e-4;
double Sqrt(double n) {
  int digitCount = log10(n) + 1;
  double b = 2 * pow(10, ((int)n & 1) ? ceil((digitCount - 1) / 2)
                                      : floor((digitCount - 1) / 2));
  double h = n / b;
  while (abs(n - b * b) > epsilon) {
    cout << b << " ";
    b = (h + b) / 2;
    h = n / b;
  }
  return b;
}

int main() {
  double n;
  cin >> n;
  cout << Sqrt(n) << endl;
  return 0;
}