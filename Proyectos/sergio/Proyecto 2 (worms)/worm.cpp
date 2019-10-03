#include "worm.h"
#include "point.h"
#include "util.h"
#include <cmath>
#include <iostream>
using namespace std;

Worm::Worm(int size, int screenW, int screenH)
    : xLimit(screenW), yLimit(screenH) {
  pushPointInFront(Point(Util::random(0, screenW), Util::random(0, screenH)));
  // pushPointInFront(Point(Util::random(0, 10), Util::random(0, 10)));

  double rad = (Util::random(0, 360) * Util::PI) / 180.0;
  direction = Point(std::cos(rad), std::sin(rad));
  for (int i = 1; i < size; i++) {
    pushPointInFront(nextPoint());
  }
  color = Color();
}

int Worm::size() { return points.size(); }

int rotationTime = 30;

Point Worm::nextPoint() {
  Move currMove = (Move)Util::random(0, 2);
  if (rotateCountLeft > 0)
    currMove = Move::turnLeft;
  if (rotateCountRight > 0)
    currMove = Move::turnRight;
  if (straightCount > 0)
    currMove = Move::goStraight;
  Point next;
  if (currMove == Move::turnLeft) {
    if (lastMove != Move::turnLeft || points.size() == 1) {
      radius = direction.perpendicularRight() * Util::random(10, 25);
      unitRadius = direction.perpendicularRight();
      circleCenter = points.front() + radius;
      deg = 0;
    }
    if (rotateCountLeft == 0) rotateCountLeft = rotationTime;
    rotateCountLeft--;
    direction = (unitRadius * -1).rotate(-deg).perpendicularRight();
    next = (radius * -1).rotate(-deg) + circleCenter;
    deg += 6;
  } else if (currMove == Move::turnRight) {
    if (lastMove != Move::turnRight || points.size() == 1) {
      radius = direction.perpendicularLeft() * Util::random(10, 25);
      unitRadius = direction.perpendicularLeft();
      circleCenter = points.front() + radius;
      deg = 0;
    }
    if (rotateCountRight == 0) rotateCountRight = rotationTime;
    rotateCountRight--;
    direction = (unitRadius * -1).rotate(deg).perpendicularLeft();
    next = (radius * -1).rotate(deg) + circleCenter;
    deg += 6;
  } else {
    if (straightCount > 0)
      straightCount--;
    else
      straightCount = 100;
    next = points.front() + direction;
  }
  lastMove = currMove;
  return Util::mod(next, xLimit, yLimit);
}

void Worm::pushPointInFront(const Point p) { points.push_front(p); }

void Worm::popPointFromBack() { points.pop_back(); }

void Worm::move() {
  popPointFromBack();
  pushPointInFront(nextPoint());
}

std::deque<Point> Worm::getPoints() { return points; }

Color Worm::getColor() { return color; }