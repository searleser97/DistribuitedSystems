#include <iostream>
using namespace std;
#define numeroElementos 100000000
int main() {
  int *arreglo, i;
  arreglo = new int[numeroElementos];
  for (i = 0; i < numeroElementos; i++)
    arreglo[i] = 0;
  int limit = 4.2e8;
  for (i = 0; i < limit; i++) {
    arreglo[rand() % numeroElementos] = rand();
  }
}