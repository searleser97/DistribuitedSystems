#include <bits/stdc++.h>
using namespace std;
#include "Request.h"
#include "Message.h"

int main(int argc, char * argv[]) {
  int port = 1000;
  int a = stoi(argv[1]), b = stoi(argv[2]);
  char * ip = argv[3];
  int args[2];
  args[0] = a;
  args[1] = b;
  Request* req;
  Message* msg = (Message*) req->doOperation(ip, port, Code::allowedOperations::suma, (char*) args);
  cout << msg->arguments[0] << endl;
  return 0;
}