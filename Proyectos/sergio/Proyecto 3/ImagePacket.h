#ifndef IMAGEPACKET_H
#define IMAGEPACKET_H
#include <string>
class ImagePacket {
  public:
    ImagePacket();
    ImagePacket(const char * name, unsigned short quality, char * bytes, size_t len);
    char * name;
    unsigned short quality;
    char * bytes;
};
#endif