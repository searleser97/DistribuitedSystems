#ifndef Coordenada_H_
#define Coordenada_H_

class Coordenada {
	private:
		double x;
		double y;
		double z;
	public:
		Coordenada();
		Coordenada(double x, double y, double z);
		double getX();
		double getY();
		double getZ();
};

#endif
