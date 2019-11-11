// Programa para crear registros de votos [celular, CURP, partido, separador],
// con el campo "celular" como clave

#include <fcntl.h>
#include <iostream>
#include <iterator>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct registro {
  char celular[11];
  char CURP[19];
  char partido[4];
};

int main(int argc, char *argv[]) {
  srand(time(0));
  char telefono[11], curp[19], sexo;
  int i, n, j, inicial, elemento;

  struct registro reg1;
  vector<int> lista;

  // Partidos disponibles 2018
  char const partidos[9][4] = {"PRI", "PAN", "PRD", "P_T", "VDE",
                               "MVC", "MOR", "PES", "PNL"};

  // Entidades federativas
  char const entidad[32][3] = {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM",
                               "DF", "DG", "GT", "GR", "HG", "JC", "MC", "MN",
                               "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP",
                               "SL", "SR", "TC", "TL", "TS", "VZ", "YN", "ZS"};

  if (argc != 3) {
    printf("Forma de uso: programa numero_registros nombre_archivo_salida\n");
    exit(0);
  }

  FILE* f = fopen(argv[2], "wb+");

  // Numero de registros n
  n = atoi(argv[1]);

  // Llena una lista con numeros telefonicos de 9 digitos secuenciales creibles
  inicial = 500000000 + rand() % 100000000;
  for (int i = inicial; i < inicial + n; i++) {
    lista.push_back(i);
  }

	random_shuffle(lista.begin(), lista.end());

  for (j = 0; j < n; j++) {
    // Obtiene un elemento aleatorio de la lista de telefonos y lo elimina de la
    // lista para evitar la repeticion
    elemento = lista[j];
    sprintf(telefono, "5%9d", elemento);
    strcpy(reg1.celular, telefono);

    if (rand() % 2 == 0)
      sexo = 77;
    else
      sexo = 72;

    i = rand() % 32;
    sprintf(curp, "%c%c%c%c%c%c%c%c%c%c%c%s%c%c%c%c%c", 65 + rand() % 25,
            65 + rand() % 25, 65 + rand() % 25, 65 + rand() % 25,
            rand() % 10 + 48, rand() % 10 + 48, rand() % 10 + 48,
            rand() % 10 + 48, rand() % 10 + 48, rand() % 10 + 48, sexo,
            entidad[i], 65 + rand() % 25, 65 + rand() % 25, 65 + rand() % 25,
            rand() % 10 + 48, rand() % 10 + 48);
    strcpy(reg1.CURP, curp);

    i = rand() % 9;
    strcpy(reg1.partido, partidos[i]);

    fprintf(f, "%s%s%s\n", reg1.celular, reg1.CURP, reg1.partido);
  }
  fclose(f);
}
