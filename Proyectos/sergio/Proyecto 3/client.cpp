#include "ImagePacket.h"
#include "Request.h"
#include "Util.h"
#include <arpa/inet.h>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

void saveFile(string path, char *bytes, unsigned size) {
  ofstream file(path, ios::binary);
  file.write(bytes, size);
  file.close();
}

void requestScreenShots(string serverIp, int port,
                                unsigned short quality, unsigned int interval) {
  size_t len_reply;
  while (true) {
    try {
      ImagePacket *imgpack = (ImagePacket *)Request::doOperation(
          serverIp, port, Message::AllowedOperations::image,
          (char *)new ImagePacket("", quality, nullptr), 0, len_reply);
      saveFile("ScreenShots/" + imgpack->name, imgpack->bytes,
               len_reply - sizeof(char) * imgpack->name.size() -
                   sizeof(unsigned short));
    } catch (const char *msg) {
      std::cerr << msg << endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(interval));
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  string firstServerIp;
  uint16_t port;
  int serversCount, interval;
  unsigned short quality;
  cout << "Ingrese el numero de servidores: ";
  cin >> serversCount;
  cout << "Ingrese la direccion ip del primer servidor";
  cin >> firstServerIp;
  cout << "Ingrese el puerto que utilizaran los servidores: ";
  cin >> port;
  cout << "Ingrese la calidad de las capturas de pantalla que se recibiran: ";
  cin >> quality;
  cout << "Intervalo de tiempo en el que se solicitaran las capturas de "
          "panalla: ";
  cin >> interval;
  cout << endl;
  int firstIp = ntohl(inet_addr(firstServerIp.c_str()));
  int lastIP = firstIp + serversCount - 1;
  vector<thread> requests;
  for (int i = firstIp; i != lastIP + 1; i++) {
    struct in_addr addr;
    addr.s_addr = htonl(i);
    string serverIp = string(inet_ntoa(addr));
    requests.emplace_back(requestScreenShots, serverIp, port, quality,
                          interval);
  }

  for (auto &th : requests) {
    th.join();
  }
  return 0;
}
