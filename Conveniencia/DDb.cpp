#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
using namespace std;

char random(char min, char max) { return min + rand() % (max - min + 1); }

int main(int argc, char *argv[]) {
  int destino;
  string linea;
  if (argc != 2) {
    cout << "Forma de uso: " << argv[0] <<" nombre_del_archivo\n";
    exit(0);
  }
  
  int n = 26 * 26 * 26 * 100, m = 3;
  string resultado;
  for(int i = 0; i < n; ++i) {
    string palabra;
    for(int j = 0; j < m; ++j){
      palabra += random('A', 'Z');
    }
    resultado += palabra + " ";
  }

  if ((destino = open(argv[1], O_WRONLY|O_CREAT, 0666)) == -1) {
    perror(argv[1]);
    exit(-1);
  }
  for (size_t i = 0; i < resultado.size(); i += m + 1) {
    write(destino, resultado.c_str() + i, m + 1);
  }
  fsync(destino);
  close(destino);
}
