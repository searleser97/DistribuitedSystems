#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double Sqrt(double n) {
	double x0 = 0, x1 = 0.5;
	while(abs(x0 - x1) >= 1e-6) {
		x0 = x1;
		x1 = 0.5 * (x0 + n / x0);
	}
	return x1;
}

int main() {
	double n;
	cout << "Enter the value of n = ";
	cin >> n;
	cout << fixed << setprecision(4) << "The square root of " << n << " is " << Sqrt(n) << ".\n";
	return 0;
}
