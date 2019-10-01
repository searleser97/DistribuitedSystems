#include "worm.h"
#include "util.h"

Worm::Worm(int size, int screenW, int screenH) : xLimit(screenW), yLimit(screenH) {
  pushPointInFront(Point(Util::random((int)0, (int)screenW),
                  Util::random((int)0, (int)screenH)));
  for (int i = 1; i < size; i++) {
    pushPointInFront(nextPoint());
  }
  color = Color();
}

int Worm::size() {
  return points.size();
}

int lastMove = 1;
enum Move {
  turnRight,
  turnLeft,
  goStraight
};

Point Worm::nextPoint() {
  Point front = points.front();
  Move currMove = (Move) Util::random(1, 3);
  int x, y;
  if (currMove == Move::turnLeft) {

  } else if (currMove == Move::turnRight) {

  } else {
    if (lastMove != Move::goStraight) {

    }

  }
  lastMove = currMove;
  return Point(x, y);
  // return Point(Util::mod(front.X() + 1, xLimit), Util::mod(front.Y(), yLimit));
}

void Worm::pushPointInFront(const Point p) {
  points.push_front(p);
}

void Worm::popPointFromBack() {
  points.pop_back();
}

void Worm::move() {
  pushPointInFront(nextPoint());
  popPointFromBack();
}

std::deque<Point> Worm::getPoints() {
  return points;
}

Color Worm::getColor() {
  return color;
}