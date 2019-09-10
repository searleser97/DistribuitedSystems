#include <iostream>
#include <iomanip>
#include "Fraccion.h"
using namespace std;

int main() {
	int num, den;
	cout << "Numerator = ";
	cin >> num;
	cout << "Denominator = ";
	cin >> den;
	Fraccion frac(num, den);
	cout << frac.toString() << " = " << frac.reduce().toString() << " = " << frac.toDouble() << "\n";
	return 0;
}
