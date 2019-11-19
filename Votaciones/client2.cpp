#include "Request.h"
#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <sys/time.h>

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

Request r;
const int num_servers = 2;
vector<thread> ths;
vector<registro> registros[num_servers];

void enviarVoto(const string & ip, uint16_t puerto, registro *reg) {
	size_t len_reply;
  try {
    TimeVal tv = *(TimeVal *)r.doOperation(ip, puerto,
                                   Message::allowedOperations::registerVote,
                                   (char *)reg, sizeof(registro), len_reply);
  } catch (const char *msg) {
    throw msg;
  }
}

void handler(const string & ip, uint16_t puerto, int pos){
	for(int i = 0; i < registros[pos].size(); ++i){
    try {
  		enviarVoto(ip, puerto, &registros[pos][i]);
    } catch(const char *msg){
      cerr << msg << "\n";
    }
	}
}

int main(int argc, char *argv[]) {
  string ip[num_servers];
  uint16_t puerto;
  cout << "Direcciones IPs de los servidores: ";
  for (int i = 0; i < num_servers; i++) cin >> ip[i];
  cout << "Puerto de los servidores: ";
  cin >> puerto;
  int n = atoi(argv[1]);
  FILE *f = fopen(argv[2], "rb");
  registro reg;
    while (n-- &&
         fscanf(f, "%10s%18s%3s", reg.celular, reg.CURP, reg.partido) != EOF) {
					 int last = reg.celular[9] - '0';
					 registros[last%num_servers].push_back(reg);
  }
  fclose(f);

	for(int i = 0; i < num_servers; ++i){
		ths.emplace_back(handler, ip[i], puerto, i);
	}

	for(int i = 0; i < num_servers; ++i){
		ths[i].join();
	}

  return 0;
}
