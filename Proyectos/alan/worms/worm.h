#ifndef worm_H_
#define worm_H_

#include <cmath>
#include "point.h"
#include "curve.h"

class Worm {
	private:
		int color[3];
		double velocity;
		double t;
		Curve c;
		double duration;
	public:
		Worm(double velocity = 1000 * M_PI);
		Point getNextPoint();
		int getR();
		int getG();
		int getB();
		static double aleatorio(double a, double b);
		static int aleatorio_int(int a, int b);
};

#endif
