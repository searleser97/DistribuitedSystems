#ifndef point_H_
#define point_H_

class Point {
	private:
		double x;
		double y;
	public:
		Point();
		Point(double x, double y);
		double getX();
		double getY();
		Point operator+(const Point & p) const;
		Point operator-(const Point & p) const;
		Point operator*(const double & k) const;
		Point operator/(const double & k) const;
		double length() const;
		Point rotate(const double & theta) const;
};

#endif
