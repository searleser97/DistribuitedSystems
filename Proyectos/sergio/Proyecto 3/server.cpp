#include <chrono>
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <sys/stat.h>
#include <thread>
#include <unordered_map>

#include "ImagePacket.h"
#include "Reply.h"
#include "Util.h"

using namespace std;

string genFileName(string ip, int requestId) {
  return ip + "_" + to_string(requestId) + ".png";
}

size_t getFileSize(string path) {
  struct stat stat_buf;
  int rc = stat(path.c_str(), &stat_buf);
  return rc == 0 ? stat_buf.st_size : -1;
}

char *captureScreenShot(string path, u_short quality) {
  string sysCommand = "scrot -q " + to_string(quality) + " " + path;
  system(sysCommand.c_str());
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  ifstream file;
  file.open(path, ios::in | ios::binary | ios::ate);
  char *img;
  if (file.is_open()) {
    streampos size = file.tellg();
    img = new char[size];
    file.seekg(0, ios::beg);
    file.read(img, size);
    char *aux = new char[size];
    file.close();
  }
  return img;
}

int main(int argc, char *argv[]) {
  uint16_t puerto;
  cout << "Puerto en el que se va a escuchar: ";
  cin >> puerto;
  Reply reply(puerto);
  cout << "Servidor iniciado...\n";
  unordered_map<string, int> nbd;
  while (1) {
    Message *msg = reply.getRequest();
    int *nums = (int *)msg->arguments;
    // cout << "Solicitud enviada desde el cliente " << reply.address << ":" <<
    // reply.port << "\n"; cout << " requestId=" << msg->requestId << "\n"; cout
    // << " operation =" << msg->operation << "\n"; cout << " sizeof(args)=" <<
    // msg->length << "\n";
    if (msg->operation == Message::AllowedOperations::sum) {
      // cout << " Numeros a sumar: " << nums[0] << " y " << nums[1] << "\n";
      int suma = nums[0] + nums[1];
      reply.sendReply((char *)&suma, sizeof(suma));
    } else if (msg->operation == Message::AllowedOperations::transfer) {
      nbd[reply.address] += nums[0];
      reply.sendReply((char *)&nbd[reply.address], sizeof(int));
    } else if (msg->operation == Message::AllowedOperations::getBalance) {
      reply.sendReply((char *)&nbd[reply.address], sizeof(int));
    } else if (msg->operation == Message::AllowedOperations::image) {
      string filename = genFileName(reply.address, reply.requestId);
      ImagePacket *imgpackIn = (ImagePacket *)msg->arguments;
      cout << imgpackIn->quality << endl;
      char *img = captureScreenShot("tmp/" + filename, imgpackIn->quality);
      size_t dataLen = getFileSize("tmp/" + filename);

      ImagePacket *imgpackOut =
          new ImagePacket(filename, imgpackIn->quality, img, dataLen);
      reply.sendReply((char *)imgpackOut, dataLen + sizeof(unsigned short) +
      sizeof(char) * filename.size());
    }
    // cout << "\n";
  }
  return 0;
}
