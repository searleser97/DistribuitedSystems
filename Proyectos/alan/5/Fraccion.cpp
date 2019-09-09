#include "Fraccion.h"
#include <cassert>
#include <cmath>

int gcd(int a, int b) {
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

Fraccion::Fraccion(int num, int den) {
	assert(den != 0);
	if (den < 0) {
		num = -num;
		den = -den;
	}
	this->num = num;
	this->den = den;
}

double Fraccion::toDouble() {
	return (double)num / den;
}

string Fraccion::toString() {
	if (den == 1) {
		return to_string(num);
	} else {
		return to_string(num) + "/" + to_string(den);
	}
}

Fraccion Fraccion::reduce() {
	int d = gcd(abs(num), den);
	return Fraccion(num / d, den / d);
}
