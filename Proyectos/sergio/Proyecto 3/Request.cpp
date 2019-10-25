#include "Request.h"
#include "Util.h"
#include <chrono>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string.h>

#include "ImagePacket.h"

char *Request::doOperation(const std::string addr, uint16_t iport,
                           Message::AllowedOperations operation,
                           char *arguments, size_t len, size_t &len_reply) {
  char *ans = new char[0];
  Message *msgToReceive = new Message();
  msgToReceive->MF = 1;
  Message *msgToSend = new Message();
  msgToSend->type = Message::Type::request;
  msgToSend->requestId =
      Util::random(0ull, std::numeric_limits<unsigned long long>::max());
  msgToSend->operation = operation;
  memcpy(msgToSend->arguments, arguments, len);
  msgToSend->length = len;
  DatagramPacket pq((char *)msgToSend, sizeof(Message), addr, iport);
  DatagramSocket sock;
  while (msgToReceive->MF == 1) {
    DatagramPacket pqresp((char *)msgToReceive, sizeof(Message));
    int i;
    for (i = 0; i < 7; i++) {
      try {
        sock.send(pq);
        sock.receiveTimeout(pqresp, 3, 0);
        std::cout << "msgToREceiveOffset: " << msgToReceive->length
                  << std::endl;
        ans = (char *)realloc(ans, msgToSend->offset + msgToReceive->length);
        memcpy(ans + msgToSend->offset, msgToReceive->arguments,
               msgToReceive->length);
        msgToSend->offset += msgToReceive->length;
        std::cout << msgToSend->offset << std::endl;
        break;
      } catch (const char *msg) {
        std::cerr << msg << '\n';
      }
    }
    if (i == 7) {
      len_reply = 0;
      throw "All attempts failed, server not available";
    }
  }
  len_reply = msgToSend->offset;
  ImagePacket *img = (ImagePacket *)ans;
  std::cout << img->quality << std::endl;
  std::cout << "Image Name:" << std::endl;
  std::cout << img->name << std::endl;
  return ans;
}

Request::Request() {}
