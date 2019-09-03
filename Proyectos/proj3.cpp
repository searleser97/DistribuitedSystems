#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double seconds;
  cin >> seconds;
  double hours = seconds / 3600;
  double hrsDecimals = hours - (int)(hours);
  double mins = hrsDecimals * 60;
  double minsDecimals = mins - (int)(mins);
  double secs = minsDecimals * 60;
  cout << "\nTIEMPO (hh:mm:ss): ";
  cout << std::setw(2) << std::setfill('0');
  cout << (int)(hours) << ":";
  cout << std::setw(2) << std::setfill('0');
  cout << (int)(mins) << ":";
  cout << std::setw(2) << std::setfill('0');
  cout << (int)(secs) << "\n\n";
}