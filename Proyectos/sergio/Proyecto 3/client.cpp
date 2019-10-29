#include "include/Image.h"
#include "include/Request.h"
#include "include/Util.h"
#include <arpa/inet.h>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <cstring>

using namespace std;

void saveFile(const string &path, char *bytes, unsigned size) {
  ofstream file(path, ios::binary);
  file.write(bytes, size);
  file.close();
}

void requestScreenShots(const string &serverIp, int port,
                                unsigned short quality, unsigned int interval) {
  size_t len_reply;
  while (true) {
    try {
      char q[sizeof(quality)];
      memcpy(&q, &quality, sizeof(quality));
      Image *imgpack = (Image *)Request::doOperation(
          serverIp, port, Message::AllowedOperations::image, (char *)q, sizeof(quality), len_reply);
      cout << imgpack->name << endl;
      cout << imgpack->len << endl;
      saveFile("ScreenShots/" + string(imgpack->name), imgpack->bytes, imgpack->len);
    } catch (const char *msg) {
      std::cerr << msg << endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(interval));
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  string firstServerIp;
  uint16_t port;
  int serversCount, interval;
  freopen("~/CLionProjects/ukras3/inClient","r",stdin);
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
  serversCount = 1;
  firstServerIp = "127.0.0.1";
  port = 9000;
  quality = 50;
  interval = 10;
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
