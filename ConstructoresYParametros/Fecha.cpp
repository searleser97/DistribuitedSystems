#include "Fecha.h"
#include <iostream>
using namespace std;
Fecha::Fecha(int dd, int mm, int aaaa) : dia(dd), mes(mm), anio(aaaa) {
  for (int i = 0; i < 10000; i++) {
    arr[i] = ' ';
  }
  if ((anio < 0) || (anio > 2019)) {
    cout << "Valor ilegal para el anio!\n" << endl;
    exit(0);
  }
  if ((mes < 1) || (mes > 12)) {
    std::cout << "Valor ilegal para el mes!\n";
    exit(0);
  }
  if ((dia < 1) || (dia > 31)) {
    cout << "Valor ilegal para el dia!\n" << endl;
    exit(0);
  }
}
void Fecha::inicializaFecha(int dd, int mm, int aaaa) {
  anio = aaaa;
  mes = mm;
  dia = dd;
  return;
}
void Fecha::muestraFecha() {
  cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio
       << endl;
  return;
}

int Fecha::convierte() { return anio * 10000 + mes * 100 + dia; }

bool Fecha::leapyr() {
  if (!(anio % 400))
    return true;
  if (!(anio % 4) && (anio % 100))
    return true;
  return false;
}