#include <stdio.h> 
#include <iostream>
#include <fstream>
#include <time.h>
#include <time.h>
using namespace std;

class Tablica {
public:
	int* wskaznik = NULL;

	int rozmiar = 0;

	void podajRozmiar() {
		cout << "Podaj rozmiar tablicy: ";
		cin >> rozmiar;
	}

	void wyswietl() {
		cout << "Tablica: ";
		for (int i = 0; i < rozmiar; i++) {
			cout << wskaznik[i] << "; ";
		}
		cout << endl;
	}

	void dodajPoczatek(int j) {
		int* nowyWskaznik = new int[rozmiar + 1];
		nowyWskaznik[0] = j;
		for (int i = 0; i < rozmiar; i++) {
			nowyWskaznik[i + 1] = wskaznik[i];
		}
		delete wskaznik;
		wskaznik = nowyWskaznik;
		rozmiar++;
	}

	void dodajKoniec(int j) {
		int* nowyWskaznik = new int[rozmiar + 1];
		nowyWskaznik[rozmiar] = j;
		for (int i = 0; i < rozmiar; i++) {
			nowyWskaznik[i] = wskaznik[i];
		}
		rozmiar++;
		delete wskaznik;
		wskaznik = nowyWskaznik;
	}

	void dodajGdzies(int j, int k) {
		if (k == 0) {
			dodajPoczatek(j);
		}
		else if (k == rozmiar) {
			dodajKoniec(j);
		}
		else if (k > 0 && k < rozmiar) {
			int* nowyWskaznik = new int[rozmiar + 1];
			nowyWskaznik[k] = j;
			for (int i = 0; i < k; i++) {
				nowyWskaznik[i] = wskaznik[i];
			}
			for (int i = k; i < rozmiar; i++) {
				nowyWskaznik[i + 1] = wskaznik[i];
			}
			rozmiar++;
			delete wskaznik;
			wskaznik = nowyWskaznik;
		}
	}

	void usunPoczatek() {
		if (rozmiar > 0) {
			int* nowyWskaznik = new int[rozmiar - 1];
			for (int i = 0; i < rozmiar - 1; i++) {
				nowyWskaznik[i] = wskaznik[i + 1];
			}
			delete wskaznik;
			wskaznik = nowyWskaznik;
			rozmiar--;
		}
	}

	void usunKoniec() {
		if (rozmiar > 0) {
			int* nowyWskaznik = new int[rozmiar - 1];
			for (int i = 0; i < rozmiar - 1; i++) {
				nowyWskaznik[i] = wskaznik[i];
			}
			delete wskaznik;
			wskaznik = nowyWskaznik;
			rozmiar--;
		}
	}

	void usunGdzies(int k) {
		if (k == 0) {
			usunPoczatek();
		}
		else if (k == rozmiar - 1) {
			usunKoniec();
		}
		else if (k > 0 && k < rozmiar) {
			int* nowyWskaznik = new int[rozmiar - 1];
			for (int i = 0; i < k; i++) {
				nowyWskaznik[i] = wskaznik[i];
			}
			for (int i = k; i < rozmiar - 1; i++) {
				nowyWskaznik[i] = wskaznik[i + 1];
			}
			rozmiar--;
			delete wskaznik;
			wskaznik = nowyWskaznik;
		}
	}

	void znajdzElement(int j) {
		for (int i = 0; i < rozmiar; i++) {
			if (wskaznik[i] == j) {
				cout << "podana wartosc znajduje sie na " << i << " pozycji" << endl;
			}
		}
	}

	void wypelnij() {
		wskaznik = new int[rozmiar];
		srand(time(NULL));
		for (int i = 0; i < rozmiar; i++) {
			wskaznik[i] = rand() % 1000;
		}
	}

	void usunTablice() {
		wskaznik = NULL;
		rozmiar = 0;
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
				dodajKoniec(wartosc);
			}
			plik.close();
		}
	}
};