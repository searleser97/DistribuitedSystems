#include <iostream>
using namespace std;

int main() {
    double c = 2.5;
    double f;
    // f = (9 / 5) * c + 32.0; // version erronea
    f = (9.0 / 5.0) * c + 32.0; // version corregida
    cout << f << endl;
    return 0;
}