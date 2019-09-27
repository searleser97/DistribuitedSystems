#ifndef curve_H_
#define curve_H_

#include "point.h"

class Curve {
	private:
		Point a0;
		Point v;
		int type;
		double R, w;
	public:
		Curve();
		Curve(const Point & a0, const Point & v, int type, const double & R, const double & w);
		Point eval(const double & t);
		Point tangent(const double & t);
};

#endif
