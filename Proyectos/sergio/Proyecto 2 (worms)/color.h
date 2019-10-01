#ifndef COLOR_H
#define COLOR_H
class Color {
  private:
    int red;
    int green;
    int black;
  public:
    Color();
    Color(int r, int g, int b);
    int R();
    int G();
    int B();
};
#endif