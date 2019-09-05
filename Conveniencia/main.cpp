#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>
using namespace std;

void execAsync(const string & path, const string & param = "") {
  execl(path.c_str(), param.c_str());
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<string> fileNames;
  int opt;
  cin >> opt;
  switch (opt) {
  case -1:
    fileNames = {"DD", "DD"};
    break;
  case 0:
    fileNames = {"RAM", "RAM"};
    break;
  case 1:
    fileNames = {"CPU", "CPU"};
    break;
  case 2:
    fileNames = {"DD", "CPU"};
    break;
  case 3:
    fileNames = {"DD", "RAM"};
    break;
  case 4:
    fileNames = {"CPU", "RAM"};
    break;
  case 5:
    fileNames = {"CPU", "DD", "RAM"};
  default:
    break;
  }

  vector<string> cadenotaFiles = {"a.txt", "b.txt"};
  int count = 0;
  vector<thread> ths;
  for (auto file : fileNames) {
    if (opt == -1) {
      ths.emplace_back(execAsync, file, cadenotaFiles[count]);
      count++;
    } else
      ths.emplace_back(execAsync, file);
  }
}