#include "ImagePacket.h"
#include <string.h>

ImagePacket::ImagePacket() {}
#include <iostream>
using namespace std;
ImagePacket::ImagePacket(const char *name, unsigned short quality, char *img,
                         size_t len)
    : quality(quality) {
  strcpy(this->name, name);
  if (len) {
    memcpy(bytes, img, len);
  }
}
