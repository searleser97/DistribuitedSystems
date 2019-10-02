#include "worm.h"
#include "point.h"
#include "util.h"
#include <cmath>
#include <iostream>
using namespace std;

Worm::Worm(int size, int screenW, int screenH)
    : xLimit(screenW), yLimit(screenH) {
  pushPointInFront(Point(Util::random(0, screenW), Util::random(0, screenH)));
  double rad = (Util::random(0, 360) * Util::PI) / 180.0;
  direction = Point(std::cos(rad), std::sin(rad));
  for (int i = 1; i < size; i++) {
    pushPointInFront(nextPoint());
  }
  color = Color();
}

int Worm::size() { return points.size(); }

Point Worm::nextPoint() {
  Move currMove = (Move)Util::random(0, 2);
  Point next;
  if (currMove == Move::turnLeft) {
    double rad = (Util::random(0, 360) * Util::PI) / 180.0;
    direction = Point(std::cos(rad), std::sin(rad));
    next = points.front() + direction;
  } else if (currMove == Move::turnRight) {
    double rad = (Util::random(0, 360) * Util::PI) / 180.0;
    direction = Point(std::cos(rad), std::sin(rad));
    next = points.front() + direction;
  } else {
    next = points.front() + direction;
  }
  return Util::mod(next, xLimit, yLimit);
}

void Worm::pushPointInFront(const Point p) { points.push_front(p); }

void Worm::popPointFromBack() { points.pop_back(); }

void Worm::move() {
  popPointFromBack();
  pushPointInFront(nextPoint());
  cout << points.front().X() << " " << points.front().Y() << endl;
}

std::deque<Point> Worm::getPoints() { return points; }

Color Worm::getColor() { return color; }