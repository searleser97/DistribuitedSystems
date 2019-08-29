#include <bits/stdc++.h>
using namespace std;

class Numero {
public:
  int val;
  bool esPrimo;
};

vector<Numero> primeSieve(int n) {
  vector<Numero> sieve(n + 1);
  for (int i = 2; i < sieve.size(); i++) {
    sieve[i].esPrimo = true;
    sieve[i].val = i;
  }
  for (int i = 4; i <= n; i += 2)
    sieve[i].esPrimo = false;
  for (int i = 3; i * i <= n; i += 2)
    if (sieve[i].esPrimo)
      for (int j = i * i; j <= n; j += 2 * i)
        if (sieve[j].esPrimo)
          sieve[j].esPrimo = false;
  return sieve;
}

int main() {
  int n;
  cin >> n;
  vector<Numero> criba = primeSieve(n);
  for (auto n : criba) {
    if (n.esPrimo) {
      cout << n.val << " ";
    }
  }
  cout << endl;
  return 0;
}
