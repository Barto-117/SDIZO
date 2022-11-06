#include "ElementListy.cpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

class Lista {
public:
	int rozmiar = 0;
	ElementListy* aktualny = NULL;
	ElementListy* poczatkowy = NULL;
	ElementListy* koncowy = NULL;

	void podajRozmiar() {
		cout << "Podaj rozmiar listy: ";
		cin >> rozmiar;
	}

	void wyswietl1() {
		aktualny = poczatkowy;
		cout << "Lista: ";
		for (int i = 0; i < rozmiar; i++) {
			cout << aktualny->wartosc << " ";
			aktualny = aktualny->nastepny;
		}
		cout << endl;
	}

	void wyswietl2() {
		cout << "lista: ";
		aktualny = koncowy;
		for (int i = 0; i < rozmiar; i++) {
			cout << aktualny->wartosc << " ";
			aktualny = aktualny->poprzedni;
		}
		cout << endl;
	}

	void dodajPoczatek(int j) {
		if (rozmiar == 0) {
			poczatkowy = new ElementListy(j, NULL, NULL);
			koncowy = poczatkowy;
		}
		else
		{
			aktualny = poczatkowy;
			poczatkowy = new ElementListy(j, NULL, aktualny);
			aktualny->poprzedni = poczatkowy;
		}
		rozmiar++;
	}

	void dodajKoniec(int j) {
		if (rozmiar == 0) {
			koncowy = new ElementListy(j, NULL, NULL);
			poczatkowy = koncowy;
		}
		else
		{
			aktualny = koncowy;
			koncowy = new ElementListy(j, aktualny, NULL);
			aktualny->nastepny = koncowy;
		}
		rozmiar++;
	}

	void dodajGdzies(int j, int k) {
		if (k >= 0 && k <= rozmiar) {
			srand(time(NULL));
			if (k == 0) {
				dodajPoczatek(j);
				return;
			}

			if (k == rozmiar) {
				dodajKoniec(j);
				return;
			}

			if (k < rozmiar/2) {
				int i = 0;
				aktualny = poczatkowy;
				ElementListy* x = new ElementListy(j, NULL, NULL);
				while (aktualny->nastepny != nullptr && i < k - 1) {
					aktualny = aktualny->nastepny;
					i++;
				}
				x->nastepny = aktualny->nastepny;
				x->poprzedni = aktualny;
				aktualny->nastepny->poprzedni = x;
				aktualny->nastepny = x;
				rozmiar++;
			}
			else {
				int i = 0;
				aktualny = koncowy;
				ElementListy* x = new ElementListy(j, NULL, NULL);
				while (aktualny->poprzedni != nullptr && i < k) {
					aktualny = aktualny->poprzedni;
					i++;
				}
				x->nastepny = aktualny->nastepny;
				x->poprzedni = aktualny;
				aktualny->nastepny->poprzedni = x;
				aktualny->nastepny = x;
				rozmiar++;
			}
		}
	}

	void usunPoczatek() {
		if (rozmiar == 0) {
			return;
		}
		if (rozmiar == 1) {
			delete poczatkowy;
			rozmiar--;
			return;
		}
		aktualny = poczatkowy->nastepny;
		delete poczatkowy;
		aktualny->poprzedni = NULL;
		poczatkowy = aktualny;
		rozmiar--;
	}

	void usunKoniec() {
		if (rozmiar == 0) {
			return;
		}
		if (rozmiar == 1) {
			delete koncowy;
			rozmiar--;
			return;
		}
		aktualny = koncowy->poprzedni;
		delete koncowy;
		aktualny->nastepny = NULL;
		koncowy = aktualny;
		rozmiar--;
	}

	void usunGdzies(int k) {
		if (k == 0) {
			usunPoczatek();
		}
		else if (k == rozmiar - 1)
		{
			usunKoniec();
		}
		else if (k > 0 && k < rozmiar/2) {
			aktualny = poczatkowy;
			for (int i = 0; i < k; i++) {
				aktualny = aktualny->nastepny;
			}
			aktualny->nastepny->poprzedni = aktualny->poprzedni;
			aktualny->poprzedni->nastepny = aktualny->nastepny;
			delete aktualny;
			rozmiar--;
		}
		else if (k >= rozmiar/2 && k < rozmiar) {
			aktualny = koncowy;
			for (int i = 0; i < k; i++) {
				aktualny = aktualny->poprzedni;
			}
			aktualny->poprzedni->nastepny = aktualny->nastepny;
			aktualny->nastepny->poprzedni = aktualny->poprzedni;
			delete aktualny;
			rozmiar--;
		}
	}

	void znajdzElement(int j) {
		aktualny = poczatkowy;
		for (int i = 0; i < rozmiar; i++) {
			if (j == aktualny->wartosc) {
				cout << "podana wartosc znajduje sie na " << i << " pozycji" << endl;
			}
			aktualny = aktualny->nastepny;
		}
	}

	void wypelnij() {
		srand(time(NULL));
		ElementListy* x = new ElementListy(rand() % 1000, NULL, NULL);
		poczatkowy = x;
		for (int i = 0; i + 1 < rozmiar; i++) {
			dodajPoczatek(rand() % 1000);
		}
		aktualny = poczatkowy;
		while (true)
		{
			if (aktualny->nastepny == NULL) {
				break;
			}
			koncowy = aktualny->nastepny;
			aktualny = koncowy;
		}
	}

	void usunListe() {
		if (rozmiar == 0) {
			return;
		}
		if (rozmiar == 1)
		{
			usunPoczatek();
		}
		aktualny = poczatkowy;
		for (int i = 0; i < rozmiar-1; i++) {
			aktualny = aktualny->nastepny;
			delete aktualny->poprzedni;
		}
		delete aktualny;
		rozmiar = 0;
	}

	void wypelnijPlik() {
		ifstream plik;
		int wartosc;
		cout << "Nazwa pliku: ";
		string plikW;
		cin >> plikW;
		rozmiar = 1;
		plik.open(plikW);
		if (plik.good()) {
			int x;
			plik >> x;
			plik >> wartosc;
			ElementListy* y = new ElementListy(wartosc, NULL, NULL);
			koncowy = y;
			for (int i = 1; i < x; i++) {
				plik >> wartosc;
				dodajKoniec(wartosc);
			}
			aktualny = koncowy;
			while (true)
			{
				if (aktualny->poprzedni == NULL) {
					break;
				}
				poczatkowy = aktualny->poprzedni;
				aktualny = poczatkowy;
			}
			plik.close();
		}
	}
};