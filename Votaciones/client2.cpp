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

int main(int argc, char *argv[]) {
	string ip;
	uint16_t puerto;
	cout << "Direccion IP del servidor: ";
	cin >> ip;
	cout << "Puerto del servidor: ";
	cin >> puerto;
	Request r;
	size_t len_reply;
	int n = atoi(argv[1]);
	FILE *f = fopen(argv[2], "rb");
	registro reg;
	TimeVal tv;
	while (n-- && fscanf(f, "%10s%18s%3s", reg.celular, reg.CURP, reg.partido) != EOF) {
		try {
			tv = *(TimeVal*)r.doOperation(ip, puerto, Message::allowedOperations::registerVote, (char *)&reg, sizeof(reg), len_reply);
			// cout <<"ss:ms "<< tv.tv_sec << ":" << tv.tv_usec << '\n';
			/*if (res) {
				cout << "Voto registrado correctamente\n";
			} else {
				cout << "Ya votaste prro :v\n";
			}*/

		} catch (const char *msg) {
			std::cerr << msg << endl;
			return -1;
		}
	}
	fclose(f);
	return 0;
}
