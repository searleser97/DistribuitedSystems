#include "Request.h"
#include "Message.h"
#include "PaqueteDatagrama.h"
#include <chrono>
#include <random>
#include <stdlib.h>
#include <string.h>
#include <iostream>

std::mt19937_64
    seed(std::chrono::steady_clock::now().time_since_epoch().count());
int random(int min, int max) { // [min, max]
  return std::uniform_int_distribution<int>(min, max)(seed);
}

char *Request::doOperation(char *IP, int port,
                           Code::allowedOperations operation, char *arguments) {
  Message *msg = new Message();
  msg->messageType = Code::solicitud;
  msg->requestId = random(1, 1 << 30);
  msg->operationId = operation;
  memcpy(msg->arguments, arguments, sizeof(msg->arguments));
  PaqueteDatagrama pq((char *)msg, sizeof(Message), IP, port);
  SocketDatagrama sock;
  sock.envia(pq);
  std::cout << "alo" << std::endl;
  PaqueteDatagrama pqresp(sizeof(Message));
  sock.recibe(pqresp);
  std::cout << "efe" << std::endl;
  return pqresp.obtieneDatos();
}

Request::Request() {}