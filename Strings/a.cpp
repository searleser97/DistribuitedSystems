#include <iostream>
#include <string>
#include <ctime>
using namespace std;

char random(char min, char max) { return min + rand() % (max - min + 1); }

int main() {
  srand(time(0));
  // int n;
  // string line;
  // cin >> n;
  // getline(cin, line);
  // cin lee un token y deja un salto de linea esperando en el buffer y getline
  // lee hasta el salto de linea por lo que estariamos leyendo un string vacio
  // string cadena("ESCOM");
  // cout << cadena[6] << endl;

  // string cadena("ESCOM");
  // cout << cadena.at(6) << endl;
  // terminate called after throwing an instance of 'std::out_of_range'
  // what():  basic_string::at: __n (which is 6) >= this->size() (which is 5)


  int n = 17576 * 10, m = 3;
  string resultado;
  for(int i = 0; i < n; ++i) {
    string palabra;
    for(int j = 0; j < m; ++j){
      palabra += random('A', 'Z');
    }
    if(i) resultado += " ";
    resultado += palabra;
  }

  int apariciones = 0;
  size_t pos = resultado.find("IPN");
  while(pos != string::npos){
    apariciones++;
    pos = resultado.find("IPN", pos + 1);
  }
  cout << "Apariciones de IPN: " << apariciones << "\n";
  return 0;
}
