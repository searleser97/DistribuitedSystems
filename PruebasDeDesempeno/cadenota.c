#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char aleatorio(char min, char max) { return min + rand() % (max - min + 1); }

int main() {
  srand(time(0));
  char * cadenota = NULL;
  char * cadenita = "";
  int n = 17576 * 10, m = 3;
  for (int i = 0; i < n; i++) {
    cadenita = (char*) malloc((m + 1) * sizeof(char));
    for (int j = 0; j < m; j++) {
      cadenita[j] = aleatorio('A', 'Z');
    }
    cadenita[m] = ' ';
    cadenota = (char*) realloc(cadenota, (i + 1) * (m + 1));
    memcpy(cadenota + i * (m + 1), cadenita, m + 1);
  }
  cadenota[n * (m + 1)] = '\0';

  int apariciones = 0;
  char* pos = strstr(cadenota, "IPN");
  while(pos){
    apariciones++;
    pos = strstr(pos + 1, "IPN");
  }
  printf("Apariciones de IPN: %d\n", apariciones);
  return 0;
}