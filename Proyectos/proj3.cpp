#include <bits/stdc++.h>
using namespace std;

int main() {
  double seconds;
  cin >> seconds;
  double hours = seconds / 3600;
  double hrsDecimals = hours - floor(hours);
  double mins = hrsDecimals * 60;
  double minsDecimals = mins - floor(mins);
  double secs = minsDecimals * 60;
  cout << "\nTIME (hh:mm:ss): ";
  cout << std::setw(2) << std::setfill('0');
  cout << floor(hours) << ":";
  cout << std::setw(2) << std::setfill('0');
  cout << floor(mins) << ":";
  cout << std::setw(2) << std::setfill('0');
  cout << floor(secs) << "\n\n";
}