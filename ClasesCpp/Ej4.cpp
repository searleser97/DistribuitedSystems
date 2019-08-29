#include "Fecha.h"
#include <iostream>
using namespace std;

int main() {
    Fecha d(1, 1, 1);
    d.inicializaFecha(1, 1, 1);
    int c = 0;
    for (int i = 1; i < 2020; i++) {
        d.inicializaFecha(1, 1, i);
        c += d.leapyr();
    }
    cout << c << endl;
    return 0;
}