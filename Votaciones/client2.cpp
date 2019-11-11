#include "Request.h"
#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <random>
#include <string>

std::mt19937_64
    seed2(std::chrono::steady_clock::now().time_since_epoch().count());
int random2(int min, int max) { // [min, max]
  return std::uniform_int_distribution<int>(min, max)(seed2);
}

using namespace std;

struct registro {
  char celular[11];
  char CURP[19];
  char partido[4];
};

int main(int argc, char *argv[]) {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);
  string ip;
  uint16_t puerto;
  int nums[1];
  int n;
  cout << "Direccion IP del servidor: ";
  cin >> ip;
  cout << "Puerto del servidor: ";
  cin >> puerto;
  Request r;
  size_t len_reply;
  FILE *f = fopen(argv[1], "rb");
  registro reg;
  fscanf(f, "%10s%18s%3s", reg.celular, reg.CURP, reg.partido);
  fclose(f);
  try {
    char res =
        *r.doOperation(ip, puerto, Message::allowedOperations::registerVote,
                       (char *)&reg, sizeof(reg), len_reply);
    if (res) {
      cout << "Voto registrado correctamente\n";
    } else {
      cout << "Ya votaste prro :v\n";
    }

  } catch (const char *msg) {
    std::cerr << msg << endl;
    return -1;
  }
  return 0;
}
