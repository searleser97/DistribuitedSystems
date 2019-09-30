class Point {
private:
  double x;
  double y;

public:
  Point();
  Point(double, double);
  double getX();
  double getY();
  Point operator+(const Point&) const;
  Point operator-(const Point&) const;
  Point operator*(const double) const;
  Point operator/(const double) const;
  double magnitude() const;
};