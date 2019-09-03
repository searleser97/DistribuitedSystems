#include <iostream>
#include <unistd.h>
#include <thread>
#include <vector>
#include "Semaforo.h"
#define n 10
using namespace std;

int global = 10;
int n_hilos = 3;
vector<Semaforo> sems(n_hilos);
vector<thread> hilos;

void funcion (int hilo) {
  while (global > 0) {
    sems[hilo].wait();
    if (global >= 0)
      printf("Soy el hilo %d, y esta es la impresion %d\n", hilo, global--);
    sems[(hilo + 1) % n_hilos].post();
  }
}

int main () {
  //Inicializa los semaforos
  for (int i = 0; i < n_hilos; ++i) {
    if (i == 0) sems[i].init(1);
    else sems[i].init(0);
  }
  for (int i = 0; i < n_hilos; ++i) {
    hilos.emplace_back(funcion, i);
  }
  for (auto & hilo : hilos) {
    hilo.join();
  }
  exit(0);
}