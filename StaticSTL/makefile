prac_compo: prac_compo.cpp PoligonoIrregular.o
	g++ prac_compo.cpp PoligonoIrregular.o Coordenada.o -o prac_compo
PoligonoIrregular.o: PoligonoIrregular.cpp Coordenada.o PoligonoIrregular.h
	g++ PoligonoIrregular.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c

