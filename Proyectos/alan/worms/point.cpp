#include "point.h"
#include <cmath>

Point::Point(): x(0), y(0) {}

Point::Point(double x, double y): x(x), y(y) {}

double Point::getX() {
	return x;
}

double Point::getY() {
	return y;
}

Point Point::operator+(const Point & p) const {
	return Point(x + p.x, y + p.y);
}

Point Point::operator-(const Point & p) const {
	return Point(x - p.x, y - p.y);
}

Point Point::operator*(const double & k) const {
	return Point(x * k, y * k);
}

Point Point::operator/(const double & k) const {
	return Point(x / k, y / k);
}

double Point::length() const {
	return sqrt(x*x + y*y);
}

Point Point::rotate(const double & theta) const {
	return Point(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta));
}
