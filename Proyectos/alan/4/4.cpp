#include <iostream>
#include <iomanip>
#include <cmath>
#include "Temperatura.h"
using namespace std;

int main() {
	Temperatura temp;
	double value;
	int source, dest;

	cout << "Source unit: [0]Kelvin, [1]Fahrenheit, [2]Celsius: ";
	cin >> source;

	cout << "Value: ";
	cin >> value;

	cout << "Destination unit: [0]Kelvin, [1]Fahrenheit, [2]Celsius: ";
	cin >> dest;

	if (source == 0) {
		temp.setTempKelvin(value);
		cout << value << "°K = ";
	} else if (source == 1) {
		temp.setTempFahrenheit(value);
		cout << value << "°F = ";
	} else {
		temp.setTempCelsius(value);
		cout << value << "°C = ";
	}

	if (dest == 0) {
		cout << temp.getTempKelvin() << "°K\n";
	} else if (dest == 1) {
		cout << temp.getTempFahrenheit() << "°F\n";
	} else {
		cout << temp.getTempCelsius() << "°C\n";
	}
	
	return 0;
}
