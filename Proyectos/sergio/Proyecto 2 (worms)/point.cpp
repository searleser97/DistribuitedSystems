#include "point.h"
#include "util.h"
#include <cmath>

Point::Point() {}

Point::Point(double x, double y) : x(x), y(y) {}

double Point::X() const {
  return x;
}

double Point::Y() const {
  return y;
}

Point Point::operator+(const Point &p) const {
  return Point(x + p.x, y + p.y);
}

Point Point::operator-(const Point &p) const {
  return Point(x - p.x, y - p.y);
}

Point Point::operator*(const double &k) const {
  return Point(x * k, y * k);
}

Point Point::rotate(double deg) {
  double rad = (deg * Util::PI) / 180.0;
  double xx = x * cos(rad) - y * sin(rad);
  double yy = x * sin(rad) + y * cos(rad);
  return Point(xx, yy);
}

Point Point::perpendicularLeft() {
  return Point(-y, x);
}

Point Point::perpendicularRight() {
  return Point(y, -x);
}