#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

int global = 0;

void increment() {
  global++;
  sleep(1);
}

void decrement() {
  global--;
  sleep(1);
}

int main() {
  thread th1(increment), th2(decrement);
  th1.join();
  th2.join();
  printf("Global value: %d\n", global);
  exit(0);
}