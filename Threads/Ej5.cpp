#include <iostream>
#include <thread>
#include <atomic>
#include <unistd.h>
using namespace std;

int n = 0;

void increment(atomic<int> & variable) {
  for (int i = 0; i < n; ++i) {
    variable++;
  }
}

void decrement(atomic<int> & variable) {
  for (int i = 0; i < n; ++i) {
    variable--;
  }
}

int main() {
  cin >> n;
  atomic<int> local(0);  
  thread th1(increment, ref(local)), th2(decrement, ref(local));
  th1.join();
  th2.join();
  cout << "Local value: " << local << endl;
  exit(0);
}