#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int t;
	cout << "Enter the time in seconds = ";
	cin >> t;
	int seconds = t % 60;
	int minutes = t / 60 % 60;
	int hours = t / 3600 % 60;
	cout << "The time (hh:mm:ss) is ";
	cout << setfill('0') << setw(2) << hours << ":";
	cout << setfill('0') << setw(2) << minutes << ":";
	cout << setfill('0') << setw(2) << seconds << ".\n";
	return 0;
}
