#include "Request.h"
#include "Util.h"
#include <chrono>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <string.h>

char *Request::doOperation(const std::string addr, uint16_t iport,
                           Message::AllowedOperations operation,
                           char *arguments, size_t len, size_t &len_reply) {
  char *ans;
  Message *msgToReceive = new Message();
  msgToReceive->MF = 1;
  Message *msgToSend = new Message();
  msgToSend->type = Message::Type::request;
  msgToSend->requestId = Util::random(0ull, std::numeric_limits<unsigned long long>::max());
  msgToSend->operation = operation;
  memcpy(msgToSend->arguments, arguments, len);
  msgToSend->length = len;
  while (msgToReceive->MF == 1) {
    DatagramPacket pq((char *)msgToSend, sizeof(Message), addr, iport);
    DatagramSocket sock;
    DatagramPacket pqresp((char *)msgToReceive, sizeof(Message));
    int i;
    for (i = 0; i < 7; i++) {
      try {
        sock.send(pq);
        sock.receiveTimeout(pqresp, 3, 0);
        msgToSend->offset += msgToReceive->length;
        ans = (char*) realloc(ans, msgToSend->offset);
        memcpy(ans + msgToSend->offset, msgToReceive->arguments, msgToReceive->length);
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
  len_reply = msgToReceive->length;
  // return msgToReceive->arguments;
  return ans;
}

Request::Request() {}
