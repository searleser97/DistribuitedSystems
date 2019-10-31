#include "../include/Image.h"
#include <string.h>

Image::Image() {}
#include <iostream>
using namespace std;
Image::Image(const char *name, unsigned short quality, char *img,
                         size_t len)
    : quality(quality), len(len) {
  strcpy(this->name, name);
  if (len) {
    memcpy(bytes, img, len);
  }
}
