#ifndef IMAGEPACKET_H
#define IMAGEPACKET_H
#include <string>
class ImagePacket {
  public:
    const static size_t MAX_SIZE = 30000;
    ImagePacket();
    ImagePacket(const char * name, unsigned short quality, char * bytes, size_t len);
    char name[100];
    unsigned short quality;
    char bytes[MAX_SIZE];
    size_t len;
};
#endif