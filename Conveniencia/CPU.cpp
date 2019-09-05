#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double MAX = 1e8;

	double i = 1;
	double seno = 0;
	double coseno = 0;
	double tangente = 0;
	double logaritmo = 0;
	double raizCuadrada = 0;

	while (i < MAX) {
		seno += sin(i);
		coseno += cos(i);
		tangente += tan(i);
		logaritmo += log(i);
		raizCuadrada += sqrt(i);
		i++;
	}

	return 0;
}
