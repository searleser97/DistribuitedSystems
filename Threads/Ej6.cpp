#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
using namespace std;

int global = 0;
int n = 0;
mutex m;

void increment() {
  for (int i = 0; i < n; ++i) {
    m.lock();
    global++;
    m.unlock();
  }
}

void decrement() {
  for (int i = 0; i < n; ++i) {
    m.lock();
    global--;
    m.unlock();
  }
}

int main() {
  cin >> n;
  thread th1(increment), th2(decrement);
  th1.join();
  th2.join();
  printf("Global value: %d\n", global);
  exit(0);
}