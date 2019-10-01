#ifndef UTIL_H
#define UTIL_H
class Util {
  public:
    static const double PI;
    static int random(int min, int max);
    static double random(double min, double max);
    static int mod(int a, int b);
};
#endif