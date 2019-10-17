#include "Reply.h"
#include <iostream>
#include <string.h>

#include "ImagePacket.h"

Reply::Reply(int iport) { localSocket = new DatagramSocket(iport); }

Message *Reply::getRequest() {
  Message *msg = new Message();
  DatagramPacket pq((char *)msg, sizeof(Message));
  localSocket->receive(pq);

  address = pq.getAddress();
  port = pq.getPort();
  operation = msg->operation;
  requestId = msg->requestId;
  if (history.count({address, requestId})) {
    auto saved = history[{address, requestId}];
    std::cout << msg->offset << "/" << saved.second << std::endl;
    sendReply(saved.first + msg->offset, saved.second - msg->offset);
    return getRequest();
  }
  return msg;
}

void Reply::sendReply(const char *arguments, size_t len) {
  if (!history.count({address, requestId}))
    history[{address, requestId}] = {arguments, len};
  ImagePacket* img = (ImagePacket*) arguments;
  std::cout << img->name << std::endl;
  Message *msg = new Message();
  msg->type = Message::Type::reply;
  msg->operation = operation;
  msg->requestId = requestId;
  msg->length = len;

  if (msg->length > Message::MAX_DATA_SIZE) {
    msg->MF = 1;
    msg->length = Message::MAX_DATA_SIZE;
  }

  memcpy(msg->arguments, arguments, msg->length);

  DatagramPacket paquete((char *)msg, sizeof(Message), address, port);
  localSocket->send(paquete);
}
