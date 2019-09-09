#include <iostream>
#include <vector>
#include "Number.h"
using namespace std;

vector<Number> sieve(int n) {
	vector<Number> numbers(n + 1);
	for (int i = 0; i <= n; ++i) {
		numbers[i].value = i;
		numbers[i].isPrime = true;
	}
	numbers[0].isPrime = numbers[1].isPrime = false;
	for (int i = 4; i <= n; i += 2) {
		numbers[i].isPrime = false;
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (numbers[i].isPrime) {
			for (int j = i * i; j <= n; j += 2 * i) {
				numbers[j].isPrime = false;
			}
		}
	}
	return numbers;
}

int main(){
	int n;
	cout << "N = ";
	cin >> n;
	vector<Number> numbers = sieve(n);
	cout << "Primes less than or equal to " << n << ":\n";
	vector<Number>::iterator it;
	for (it = numbers.begin(); it != numbers.end(); ++it) {
		if (it->isPrime) {
			cout << it->value << "\n";
		}
	}
	return 0;
}
