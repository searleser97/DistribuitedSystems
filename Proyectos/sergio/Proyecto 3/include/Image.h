#ifndef IMAGE_H
#define IMAGE_H
#include <string>
class Image {
public:
  const static size_t MAX_SIZE = (int) 1e6;
  Image();
  Image(const char * name, unsigned short quality, char * bytes, size_t len);
  char name[1000];
  unsigned short quality;
  char bytes[MAX_SIZE];
  size_t len;
};
#endif