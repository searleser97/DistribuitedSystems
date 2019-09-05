#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>
using namespace std;

void execAsync(const string &path, const string &param = "") {
  system(("./" + path + " " + param).c_str());
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<string> fileNames;
  int opt = argv[1][0] - '0';
  switch (opt) {
  case 0:
    fileNames = {"DD", "DD"};
    break;
  case 1:
    fileNames = {"RAM", "RAM"};
    break;
  case 2:
    fileNames = {"CPU", "CPU"};
    break;
  case 3:
    fileNames = {"DD", "CPU"};
    break;
  case 4:
    fileNames = {"DD", "RAM"};
    break;
  case 5:
    fileNames = {"CPU", "RAM"};
    break;
  case 6:
    fileNames = {"CPU", "DD", "RAM"};
  default:
    break;
  }

  vector<string> cadenotaFiles = {"a.txt", "b.txt"};
  int count = 0;
  vector<thread> threads;
  for (auto file : fileNames) {
    if (file == "DD") {
      threads.emplace_back(execAsync, file, cadenotaFiles[count]);
      count++;
    } else
      threads.emplace_back(execAsync, file, "");
  }

  for (auto &th : threads) {
    th.join();
  }
}