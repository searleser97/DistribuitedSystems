#include "curve.h"
#include "point.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Curve::Curve(){}

Curve::Curve(const Point & a0, const Point & v, int type, const double & R, const double & w): a0(a0), v(v), type(type), R(R), w(w) {}

Point Curve::eval(const double & t) {
	if (type == 1) { //line
		return a0 + v * t;
	} else if (type == 2) { //circle
		Point u = v.rotate(M_PI / 2);
		u = u / u.length();
		v = v / v.length();
		Point center = a0 + u * R;
		return center - u * R * cos(w*t) + v * R * sin(w*t);
	} else { //sine
		Point u = v.rotate(M_PI / 2);
		u = u / u.length();
		v = v / v.length();
		double x = R * w*t - R * sin(w*t);
		double y = R * w*t + R * sin(w*t);
		return a0 + u * x + v * y;
	}
}

Point Curve::tangent(const double & t) {
	if (type == 1) { //line
		return v / v.length();
	} else if (type == 2) { //circle
		Point u = v.rotate(M_PI / 2);
		u = u / u.length();
		v = v / v.length();
		Point b = u * R * w * sin(w*t) + v * R * w * cos(w*t);
		return b / b.length();
	} else { //sine
		Point u = v.rotate(M_PI / 2);
		u = u / u.length();
		v = v / v.length();
		double x = R * w - R * w * cos(w*t);
		double y = R * w + R * w * cos(w*t);
		Point b = u * x + v * y;
		b = b / b.length();
		return b;
	}
}
