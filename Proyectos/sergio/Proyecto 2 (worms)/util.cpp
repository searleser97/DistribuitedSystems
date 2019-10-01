#include "util.h"
#include <chrono>
#include <random>
#include <cmath>
using namespace std;
mt19937_64 seed(chrono::steady_clock::now().time_since_epoch().count());

const double Util::PI = acos(-1);

int Util::random(int min, int max) { // [min, max]
  return uniform_int_distribution<int>(min, max)(seed);
}
double Util::random(double min, double max) { // [min, max)
  return uniform_real_distribution<double>(min, max)(seed);
}

int Util::mod(int a, int b) {
  if (a < 0 && b >= 0)
    return a % b + b;
  if (a >= 0 && b < 0)
    return -(a % b + b);
  return a % b;
}
