#include <chrono>
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <sys/stat.h>
#include <thread>
#include <unordered_map>

#include "include/Image.h"
#include "include/Reply.h"
#include "include/Util.h"

using namespace std;

void saveFile(const string &path, char *bytes, unsigned size) {
  ofstream file(path, ios::binary);
  file.write(bytes, size);
  file.close();
}

string genFileName(const string &ip, uint64_t requestId) {
  return ip + "_" + to_string(requestId) + ".png";
}

size_t getFileSize(const string &path) {
  struct stat stat_buf;
  int rc = stat(path.c_str(), &stat_buf);
  return rc == 0 ? stat_buf.st_size : -1;
}

char *captureScreenShot(const string &path, u_short quality) {
  string sysCommand = "scrot -q " + to_string(quality) + " " + path;
  system(sysCommand.c_str());
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  ifstream file;
  file.open(path, ios::in | ios::binary | ios::ate);
  char *img = nullptr;
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
  // puerto = 9000;
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
      int quality = *(int *)msg->arguments;
      char *img = captureScreenShot("tmp/" + filename, quality);
      size_t imglen = getFileSize("tmp/" + filename);
      Image *imgpackOut = new Image(filename.c_str(), quality, img, imglen);
      reply.sendReply((char *)imgpackOut, sizeof(Image));
    }
  }
  return 0;
}
