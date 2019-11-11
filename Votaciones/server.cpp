#include "Reply.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

struct registro {
  char celular[11];
  char CURP[19];
  char partido[4];
};

set<tuple<string, string, string>> nbd;

FILE* f;

void isr(int sig){
	if(sig == SIGINT && f){
		fclose(f);
		printf("Servidor cerrado.\n");
		exit(0);
	}
}

int main(int argc, char *argv[]) {
	signal(SIGINT, isr);
	f = fopen(argv[1], "rb+");
	registro reg;
	while(fscanf(f, "%10s%18s%3s", reg.celular, reg.CURP, reg.partido) != EOF){
		nbd.insert({reg.celular, reg.CURP, reg.partido});
	}
	fclose(f);
	f = fopen(argv[1], "ab+");
  uint16_t puerto;
  cout << "Puerto en el que se va a escuchar: ";
  cin >> puerto;
  Reply reply(puerto);
  cout << "Servidor iniciado...\n";
  while (1) {
		char res = 0;
    Message *msg = reply.getRequest();
    reg = *(registro*)msg->arguments;
    if (msg->operationId == Message::allowedOperations::registerVote) {
      // cout << " Numeros a sumar: " << nums[0] << " y " << nums[1] << "\n";
      tuple<string, string, string> t(reg.celular, reg.CURP, reg.partido);
			if(nbd.find(t) == nbd.end()){
				nbd.insert(t);
				fprintf(f, "%s%s%s\n", reg.celular, reg.CURP, reg.partido);
				fflush(f);
				res = 1;
			}
			reply.sendReply(&res, sizeof(res));
    }
    // cout << "\n";
  }
  return 0;
}
