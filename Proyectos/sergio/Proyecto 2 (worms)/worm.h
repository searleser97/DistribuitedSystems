#ifndef WORM_H
#define WORM_H
#include "point.h"
#include "color.h"
#include <deque>
class Worm {
  private:
    std::deque<Point> points;
    void pushPointInFront(const Point p);
    void popPointFromBack();
    Point nextPoint();
    Color color;
    int xLimit;
    int yLimit;
  public:
    Worm();
    Worm(int size, int screenW, int screenH);
    int size();
    void move();
    std::deque<Point> getPoints();
    Color getColor();
};
#endif