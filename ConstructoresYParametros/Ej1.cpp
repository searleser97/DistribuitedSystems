#include "Fecha.h"
#include <ctime>
#include <iostream>
using namespace std;

int random(int min, int max) { return min + rand() % (max - min + 1); }

int masVieja(Fecha &fecha1, Fecha &fecha2) {

  if (fecha1.convierte() > fecha2.convierte()) return 1;
  if (fecha1.convierte() < fecha2.convierte()) return -1;
  return 0;
}

int main() {
  Fecha f(1, 12, 2019);
  Fecha ff(31, 12, 2019);
  for (int i = 0; i < 100000; i++) {
    f.inicializaFecha(random(1, 31), random(1, 12), random(2000, 2019));
    ff.inicializaFecha(random(1, 31), random(1, 12), random(2000, 2019));
    masVieja(f, ff);
  }
  return 0;
}

// int masVieja(Fecha *fecha1, Fecha *fecha2) {

//   if (fecha1->convierte() > fecha2->convierte())
//     return 1;
//   if (fecha1->convierte() < fecha2->convierte())
//     return -1;
//   return 0;
// }

// int main() {
//   srand(time(0));
//   Fecha *f = new Fecha(1, 12, 2019);
//   Fecha *ff = new Fecha(31, 12, 2019);
//   for (int i = 0; i < 10000000; i++) {
//     f->inicializaFecha(random(1, 31), random(1, 12), random(2000, 2019));
//     ff->inicializaFecha(random(1, 31), random(1, 12), random(2000, 2019));
//     masVieja(f, ff);
//   }
//   return 0;
// }