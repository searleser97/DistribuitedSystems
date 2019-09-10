#include "Temperatura.h"

void Temperatura::setTempKelvin(double K) {
	this->K = K;
}

void Temperatura::setTempFahrenheit(double F) {
	this->K = (F - 32) / 1.8 + 273.15;
}

void Temperatura::setTempCelsius(double C) {
	this->K = C + 273.15;
}

double Temperatura::getTempKelvin() {
	return this->K;
}

double Temperatura::getTempFahrenheit() {
	return 1.8 * (this->K - 273.15) + 32;
}

double Temperatura::getTempCelsius() {
	return this->K - 273.15;
}
