#include <string>
using namespace std;

#ifndef Fraccion_H_
#define Fraccion_H_

class Fraccion {
	private:
		int num;
		int den;
	public:
		Fraccion(int num, int den);
		double toDouble();
		string toString();
		Fraccion reduce();
};

#endif
