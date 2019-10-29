#ifndef UTIL_H
#define UTIL_H
class Util {
  public:
    static const double PI;
    static unsigned long long random(unsigned long long min, unsigned long long max);
    static double random(double min, double max);
    static int mod(int a, int b);
};
#endif