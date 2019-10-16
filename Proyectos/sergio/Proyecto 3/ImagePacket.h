#ifndef IMAGEPACKET_H
#define IMAGEPACKET_H
#include <string>
class ImagePacket {
  public:
    ImagePacket();
    ImagePacket(std::string name, unsigned short quality, char * bytes);
    std::string name;
    unsigned short quality;
    char * bytes;
};
#endif