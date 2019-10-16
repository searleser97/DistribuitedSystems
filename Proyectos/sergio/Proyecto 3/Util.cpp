#include "Util.h"
#include <chrono>
#include <random>
using namespace std;
mt19937_64 seed(chrono::steady_clock::now().time_since_epoch().count());

const double Util::PI = acos(-1);

unsigned long long Util::random(unsigned long long min, unsigned long long max) { // [min, max]
  return uniform_int_distribution<unsigned long long>(min, max)(seed);
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