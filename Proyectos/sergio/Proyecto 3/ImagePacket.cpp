#include "ImagePacket.h"
#include <string.h>

ImagePacket::ImagePacket() {}
#include <iostream>
using namespace std;
ImagePacket::ImagePacket(std::string name, unsigned short quality, char *img,
                         size_t len)
    : name(name), quality(quality) {
  if (len) {
    bytes = new char[len];
    memcpy(bytes, img, len);
  }
}
