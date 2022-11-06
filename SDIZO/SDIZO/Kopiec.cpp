#include <stdio.h> 
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>
using namespace std;

class Kopiec {
public:
	int* wskaznik = NULL;

	int rozmiar = 0;

	void podajRozmiar() {
		cout << "Podaj rozmiar: ";
		cin >> rozmiar;
	}

	void wypelnij() {
		wskaznik = new int[0];
		srand(time(NULL));
		int x = rozmiar;
		rozmiar = 0;
		for (int i = 0; i < x; i++) {
			dodaj(rand() % 1000);
		}
	}

	void dodaj(int j) {
		int* nowyWskaznik = new int[rozmiar + 1];
		for (int i = 0; i < rozmiar; i++)
		{
			nowyWskaznik[i] = wskaznik[i];
		}
		nowyWskaznik[rozmiar] = j;
		delete wskaznik;
		wskaznik = nowyWskaznik;
		rozmiar++;
		doGory(rozmiar - 1);
	}

	void usunGdzies(int k) {
		if (k >= 0 && k < rozmiar) {
			int* nowyWskaznik = new int[rozmiar - 1];
			nowyWskaznik = wskaznik;
			nowyWskaznik[k] = wskaznik[rozmiar - 1];
			rozmiar--;
			wskaznik = nowyWskaznik;
			if (k == rozmiar) {
			}
			else if (wskaznik[k] > wskaznik[(k - 1) / 2] && k > 0) {
				doGory(k);
			}
			else {
				doDolu(k);
			}
		}
	}

	void doGory(int k) {
		int temp;
		while (wskaznik[k] > wskaznik[(k - 1) / 2] && k > 0) 
		{
			temp = wskaznik[k];
			wskaznik[k] = wskaznik[(k - 1) / 2];
			wskaznik[(k - 1) / 2] = temp;
			k = (k - 1) / 2;
		}
	}

	void doDolu(int k) {
		int temp;
		while (2 * k + 1 < rozmiar) 
		{
			if (wskaznik[2 * k + 1] > wskaznik[2 * k + 2]) {
				temp = wskaznik[k];
				wskaznik[k] = wskaznik[2 * k + 1];
				wskaznik[2 * k + 1] = temp;
				k = 2 * k + 1;
			}
			else {
				temp = wskaznik[k];
				wskaznik[k] = wskaznik[2 * k + 2];
				wskaznik[2 * k + 2] = temp;
				k = 2 * k + 2;
			}
		}
	}

	void wyswietl() {
		cout << "Kopiec: ";
		for (int i = 0; i < rozmiar; i++) {
			cout << wskaznik[i] << "; ";
		}
		cout << endl;
	}

	void usunKopiec() {
		wskaznik = NULL;
		rozmiar = 0;
	}

	int znajdzElemet(int j) {
		for (int i = 0; i < rozmiar; i++) {
			if (wskaznik[i] == j) {
				return i;
			}
		}
		return -1;
	}

	void wypelnijPlik() {
		ifstream plik;
		int wartosc;
		rozmiar = 0;
		cout << "Nazwa pliku: ";
		string plikW;
		cin >> plikW;
		plik.open(plikW);
		if (plik.good()) {
			int x;
			plik >> x;
			wskaznik = new int[0];
			for (int i = 0; i < x; i++) {
				plik >> wartosc;
				dodaj(wartosc);
			}
			plik.close();
		}
	}
};