#ifndef POINT_H
#define POINT_H
class Point {
private:
  double x;
  double y;

public:
  Point();
  Point(double, double);
  double X();
  double Y();
  Point operator+(const Point&) const;
  Point operator-(const Point&) const;
  Point rotate(double deg);
  double magnitude() const;
};
#endif