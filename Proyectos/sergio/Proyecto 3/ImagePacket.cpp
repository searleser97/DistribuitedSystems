#include "ImagePacket.h"

ImagePacket::ImagePacket() {}

ImagePacket::ImagePacket(std::string name, unsigned short quality, char *bytes)
    : name(name), quality(quality), bytes(bytes) {}
