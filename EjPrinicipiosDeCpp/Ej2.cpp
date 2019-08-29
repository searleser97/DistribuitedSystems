#include <iostream>
using namespace std;
int main() {
    int a = 4, b = 10;
    double c = 4.5;
    cout << (b / a) << " " << (b / c) << endl;
    // la division entre dos enteros da como resultado un entero
    // la division entre un entero y un flotante resulta en un numero flotante
    // dado que el compilador de c++ hace casteos por defecto al tipo de dato de mayor
    // jerarquia en la operacion
    return 0;
}