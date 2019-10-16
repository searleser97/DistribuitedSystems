#include "Reply.h"
#include <string.h>

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
    sendReply(saved.first + msg->offset, saved.second - msg->offset);
    return getRequest();
  }
  return msg;
}
#include "ImagePacket.h"
#include <iostream>

void Reply::sendReply(const char *arguments, size_t len) {
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
  std::cout << sizeof(Message) << std::endl;
  if (!history.count({address, requestId}))
    history[{address, requestId}] = {msg->arguments, msg->length};

	
  DatagramPacket paquete((char *)msg, sizeof(Message), address, port);
  localSocket->send(paquete);
}
