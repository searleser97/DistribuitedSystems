#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double height(double t) {
	double g = 9.81;
	return 0.5 * g * t * t;
}

int main() {
	double t;
	cout << "Enter the time in seconds = ";
	cin >> t;
	cout << fixed << setprecision(4) << "The height of the building is " << height(t) << " meters.";
	return 0;
}
