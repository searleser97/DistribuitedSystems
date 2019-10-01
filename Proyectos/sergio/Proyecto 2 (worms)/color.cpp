#include "color.h"
#include "util.h"

Color::Color() {
  red = Util::random(0, 255);
  green = Util::random(0, 255);
  black = Util::random(0, 255);
}

Color::Color(int r, int g, int b) : red(r), green(g), black(b) {}

int Color::R() {
  return red;
}

int Color::G() {
  return green;
}

int Color::B() {
  return black;
}