#include "Reply.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>
#include <sys/time.h>
#include "Trie.h"

// struct timeval {
// 	time_t tv_sec; /* segundos */
// 	suseconds_t tv_usec; /* microsegundos */
// };

typedef struct timeval TimeVal;

using namespace std;

struct registro {
  char celular[11];
  char CURP[19];
  char partido[4];
};

Trie trie;
set <string> nbd;

FILE* f;
FILE *fileTimes;

void isr(int sig){
	if(sig == SIGINT){
		if(f){
			fclose(f);
		}
		if(fileTimes){
			fclose(fileTimes);
		}
		printf("Servidor cerrado.\n");
		exit(0);
	}
}

int main(int argc, char *argv[]) {
	signal(SIGINT, isr);

	registro reg;
	
	f = fopen(argv[1], "rb+");
	fileTimes = fopen((string(argv[1])+"Time").c_str(), "ab+");
	
	if (f) {
		while(fscanf(f, "%10s%18s%3s", reg.celular, reg.CURP, reg.partido) != EOF) {
			trie.insert(string(reg.celular) + string(reg.CURP) + string(reg.partido));
		}
		fclose(f);
	}

	f = fopen(argv[1], "ab+");
	uint16_t puerto;
	cout << "Puerto en el que se va a escuchar: ";
	cin >> puerto;
	Reply reply(puerto);
	cout << "Servidor iniciado...\n";
	TimeVal tv;
	while (1) {
		char res = 0;
		Message *msg = reply.getRequest();
		reg = *(registro*)msg->arguments;
		tv.tv_sec = 0;
		tv.tv_usec = 0;
		if (msg->operationId == Message::allowedOperations::registerVote) {
			string id = string(reg.celular) + string(reg.CURP) + string(reg.partido);
			if (!trie.strCount(id)) {
				gettimeofday(&tv, NULL);//get time
				trie.insert(id);
				fprintf(f, "%s%s%s\n", reg.celular, reg.CURP, reg.partido);
				fflush(f);
				res = 1;
				fprintf(fileTimes, "%d:%d\n", tv.tv_sec, tv.tv_usec);
				fflush(fileTimes);
			}
			reply.sendReply((char*)&tv, sizeof(tv));
		}
	}
	return 0;
}
