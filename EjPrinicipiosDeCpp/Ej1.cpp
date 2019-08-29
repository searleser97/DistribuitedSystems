#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);

int main() {
    // PI = 3.14159; // no se puede modificar una variable constante
    double radio;
    cin >> radio;
    cout << "El area del circulo es: " << (PI * radio * radio) << "\n";
    return 0;
}
