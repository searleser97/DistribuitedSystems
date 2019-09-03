#include <iostream>
#include <thread>
#include <atomic>
#include <unistd.h>
using namespace std;

atomic<int> global(0);
int n = 0;

void increment() {
  for (int i = 0; i < n; ++i) {
    global++;
  }
}

void decrement() {
  for (int i = 0; i < n; ++i) {
    global--;
  }
}

int main() {
  cin >> n;
  thread th1(increment), th2(decrement);
  th1.join();
  th2.join();
  cout << "Global value: " << global << endl;
  exit(0);
}