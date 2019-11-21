#include "Reply.h"
#include "Request.h"
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

timeval add(TimeVal a, TimeVal b){
	int64_t ta = a.tv_sec*1000000 + a.tv_usec;
	int64_t tb = b.tv_sec*1000000 + b.tv_usec;
	int64_t tc = ta + tb;
	TimeVal ans;
	ans.tv_sec = tc/1000000;
	ans.tv_usec = tc%1000000;
	return ans;
}

timeval subtract(TimeVal a, TimeVal b){
	int64_t ta = a.tv_sec*1000000 + a.tv_usec;
	int64_t tb = b.tv_sec*1000000 + b.tv_usec;
	int64_t tc = ta - tb;
	TimeVal ans;
	ans.tv_sec = tc/1000000;
	ans.tv_usec = tc%1000000;
	return ans;
}

timeval divide(TimeVal a, int64_t k){
	int64_t ta = a.tv_sec*1000000 + a.tv_usec;
	ta /= k;
	TimeVal ans;
	ans.tv_sec = ta/1000000;
	ans.tv_usec = ta%1000000;
	return ans;
}

int main(int argc, char *argv[]) {
	signal(SIGINT, isr);

	registro reg;
	
	f = fopen(argv[1], "rb+");
	fileTimes = fopen((string(argv[1])+"Time").c_str(), "ab+");
	
	if (f) {
		while(fscanf(f, "%10s%18s%3s", reg.celular, reg.CURP, reg.partido) != EOF) {
			nbd.insert({string(reg.celular), string(reg.CURP), string(reg.partido)});
		}
		fclose(f);
	}

	f = fopen(argv[1], "ab+");
	uint16_t puerto;
	cout << "Puerto en el que se va a escuchar: ";
	cin >> puerto;
	Reply reply(puerto);
	Request r;
	cout << "Servidor iniciado...\n";
	
	string ip_time;
	int puerto_time;

	cin >> ip_time >> puerto_time;
	
	TimeVal tv_client, tv_server, tv_after, tv_real;
	while (1) {
		char res = 0;
		Message *msg = reply.getRequest();
		reg = *(registro*)msg->arguments;
		if (msg->operationId == Message::allowedOperations::registerVote) {
			string id = string(reg.celular) + string(reg.CURP) + string(reg.partido);
			if (!nbd.count(id)) {
				memset(&tv_client, 0, sizeof(TimeVal));
				memset(&tv_server, 0, sizeof(TimeVal));
				memset(&tv_after, 0, sizeof(TimeVal));
				memset(&tv_real, 0, sizeof(TimeVal));
				gettimeofday(&tv_client, NULL);//get time
				size_t len_reply;
				tv_server = *(TimeVal *)r.doOperation(ip_time, puerto_time,
                                   Message::allowedOperations::getTime,
                                   NULL, 0, len_reply);
				gettimeofday(&tv_after, NULL);
				tv_real = add(tv_server, divide(subtract(tv_after, tv_client), 2));
				nbd.insert(id);
				fprintf(f, "%s%s%s\n", reg.celular, reg.CURP, reg.partido);
				fflush(f);
				res = 1;
				fprintf(fileTimes, "%d:%d\n", tv_real.tv_sec, tv_real.tv_usec);
				fflush(fileTimes);
			}
			reply.sendReply((char*)&tv_real, sizeof(tv_real));
		}
	}
	return 0;
}
