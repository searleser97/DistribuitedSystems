#include "worm.h"
#include "point.h"
#include "curve.h"
#include <vector>
#include <cmath>
#include <chrono>
#include <random>

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// std::default_random_engine rng;
double Worm::aleatorio(double a, double b) {
	uniform_real_distribution<double> dist(a, b);
	return dist(rng);
}

int Worm::aleatorio_int(int a, int b){
	uniform_int_distribution<int> dist(a, b);
	return dist(rng);
}

Worm::Worm(double velocity): velocity(velocity) {
	Point a0(Worm::aleatorio(400, 600), Worm::aleatorio(400, 600));
	double theta = Worm::aleatorio(0, 2 * M_PI);
	Point v = Point(cos(theta), sin(theta)) * velocity;
	double R = Worm::aleatorio(10, 200);
	int type = Worm::aleatorio_int(1, 3);
	c = Curve(a0, v, type, R, velocity / R);
	t = 0;
	duration = Worm::aleatorio(0, 0.5);
	for (int i = 0; i < 3; ++i) {
		color[i] = Worm::aleatorio_int(0, 255);
	}
}

Point Worm::getNextPoint() {
	if (t > duration) {
		Point a0 = c.eval(t);
		Point v = c.tangent(t) * velocity;
		double R = Worm::aleatorio(10, 200);
		int type = Worm::aleatorio_int(1, 3);
		c = Curve(a0, v, type, R, velocity / R);
		t = 0;
		duration = Worm::aleatorio(0, 0.5);
	}
	Point ans = c.eval(t);
	t += 1e-3;
	return ans;
}

int Worm::getR() {
	return color[0];
}

int Worm::getG() {
	return color[1];
}

int Worm::getB() {
	return color[2];
}
