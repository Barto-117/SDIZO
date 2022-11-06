#include <fstream>
#include <stdio.h> 

class ElementListy {
public:
	int wartosc;
	ElementListy* poprzedni;
	ElementListy* nastepny;

	ElementListy(int war, ElementListy* pop, ElementListy* nas) {
		wartosc = war;
		poprzedni = pop;
		nastepny = nas;
	}
};