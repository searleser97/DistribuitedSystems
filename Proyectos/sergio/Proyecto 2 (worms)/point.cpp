#include "point.h"
#include "util.h"
#include <cmath>

Point::Point(double x, double y) : x(x), y(y) {}

double Point::X() {
  return x;
}

double Point::Y() {
  return y;
}

Point Point::operator+(const Point &p) const {
  return Point(x + p.x, y + p.y);
}

Point Point::operator-(const Point &p) const {
  return Point(x - p.x, y - p.y);
}

Point Point::rotate(double deg) {
  deg = (deg * Util::PI) / 180;
  double xx = x * cos(deg) - y * sin(deg);
  double yy = x * sin(deg) + y * cos(deg);
  return Point(xx, yy);
}