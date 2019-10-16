#ifndef IMAGEPACKET_H
#define IMAGEPACKET_H
#include <string>
class ImagePacket {
  public:
    ImagePacket();
    ImagePacket(std::string name, unsigned short quality, char * bytes, size_t len);
    std::string name;
    unsigned short quality;
    char * bytes;
};
#endif