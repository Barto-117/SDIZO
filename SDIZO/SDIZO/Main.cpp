#include "Tablica.cpp"
#include "Lista.cpp"
#include "Kopiec.cpp"
#include "Czas.cpp"
#include <iostream>

using namespace std;

int main()
{   
    int wybor = 99;
    Czas czas;
    int wartosc;
    int pozycja;
    Kopiec kopiec;
    Lista lista;
    Tablica tablica;

    while (wybor != 4) {
        tablica.usunTablice();
        lista.usunListe();
        kopiec.usunKopiec();

        cout << "Wybierz strukture:" << endl;
        cout << "   1. Tablica" << endl;
        cout << "   2. Lista" << endl;
        cout << "   3. Kopiec" << endl;
        cout << "   4. Wyjscie" << endl;
        cout << "Wybor: ";
        cin >> wybor;
        switch (wybor)
        {
        default:
            break;
        case 4:
            break;
        case 1:
            do {
                cout << "   1. Utworz losowo" << endl;
                cout << "   2. Utworz z pliku" << endl;
                cout << "Wybor: ";
                cin >> wybor;
                switch (wybor)
                {
                case 1:
                    tablica.podajRozmiar();
                    tablica.wypelnij();
                    break;
                case 2:
                    tablica.wypelnijPlik();
                    break;        
                }
            } while (wybor > 2 || wybor < 1);
       
            while (wybor != 0) {
                cout << "Wybierz funkcje tablicy:" << endl;
                cout << "    1. Dodaj na poczatek" << endl;
                cout << "    2. Dodaj na koniec" << endl;
                cout << "    3. Dodaj gdziekolwiek" << endl;
                cout << "    4. Usun pierwszy" << endl;
                cout << "    5. Usun ostatni" << endl;
                cout << "    6. Usun ktorykolwiek" << endl;
                cout << "    7. Wyszukaj element" << endl;
                cout << "    8. Wydrukuj tablice" << endl;
                cout << "    0. Wyjscie" << endl << endl;
                cout << "Wybor: ";
                cin >> wybor;
                switch (wybor) {
                default:
                    cout << "Bledny wybor!" << endl;
                    break;

                case 0:
                    break;

                case 1:
                    cout << "Podaj wartosc: ";
                    cin >> wartosc;
                    czas.czasStart();
                    tablica.dodajPoczatek(wartosc);
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 2:
                    cout << "Podaj wartosc: ";
                    cin >> wartosc;
                    czas.czasStart();
                    tablica.dodajKoniec(wartosc);
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 3:
                    cout << "Podaj wartosc: ";
                    cin >> wartosc;
                    cout << "Podaj pozycje: ";
                    cin >> pozycja;
                    czas.czasStart();
                    tablica.dodajGdzies(wartosc, pozycja);
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 4:
                    czas.czasStart();
                    tablica.usunPoczatek();
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 5:
                    czas.czasStart();
                    tablica.usunKoniec();
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 6:
                    cout << "Podaj pozycje: ";
                    cin >> pozycja;
                    czas.czasStart();
                    tablica.usunGdzies(pozycja);
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 7:
                    cout << "Podaj wartosc: ";
                    cin >> wartosc;
                    czas.czasStart();
                    tablica.znajdzElement(wartosc);
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 8:
                    czas.czasStart();
                    tablica.wyswietl();
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;
                } 
            }
            continue;

        case 2:
            do {
                cout << "   1. Utworz losowo" << endl;
                cout << "   2. Utworz z pliku" << endl;
                cout << "Wybor: ";
                cin >> wybor;
                switch (wybor)
                {
                case 1:
                    lista.podajRozmiar();
                    lista.wypelnij();
                    break;
                case 2:
                    lista.wypelnijPlik();
                    break;
                }
            } while (wybor != 1 && wybor != 2);

            while (wybor != 0) {
                cout << "Wybierz funkcje listy:" << endl;
                cout << "    1. Dodaj na poczatek" << endl;
                cout << "    2. Dodaj na koniec" << endl;
                cout << "    3. Dodaj gdziekolwiek" << endl;
                cout << "    4. Usun pierwszy" << endl;
                cout << "    5. Usun ostatni" << endl;
                cout << "    6. Usun ktorykolwiek" << endl;
                cout << "    7. Wyszukaj element" << endl;
                cout << "    8. Wydrukuj liste" << endl;
                cout << "    0. Wyjscie" << endl << endl;
                cout << "Wybor: ";
                cin >> wybor;
                switch (wybor) {
                default:
                    cout << "Bledny wybor!" << endl;
                    break;

                case 0:
                    break;

                case 1:
                    cout << "Podaj wartosc: ";
                    cin >> wartosc;
                    czas.czasStart();
                    lista.dodajPoczatek(wartosc);
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 2:
                    cout << "Podaj wartosc: ";
                    cin >> wartosc;
                    czas.czasStart();
                    lista.dodajKoniec(wartosc);
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 3:
                    cout << "Podaj wartosc: ";
                    cin >> wartosc;
                    cout << "Podaj pozycje: ";
                    cin >> pozycja;
                    czas.czasStart();
                    lista.dodajGdzies(wartosc, pozycja);
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 4:
                    czas.czasStart();
                    lista.usunPoczatek();
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 5:
                    czas.czasStart();
                    lista.usunKoniec();
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 6:
                    cout << "Podaj pozycje: ";
                    cin >> pozycja;
                    czas.czasStart();
                    lista.usunGdzies(pozycja);
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 7:
                    cout << "Podaj wartosc: ";
                    cin >> wartosc;
                    czas.czasStart();
                    lista.znajdzElement(wartosc);
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 8:
                    czas.czasStart();
                    lista.wyswietl1();
                    lista.wyswietl2();
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                }

            }
            continue;

        case 3:
            do {
                cout << "   1. Utworz losowo" << endl;
                cout << "   2. Utworz z pliku" << endl;
                cout << "Wybor: ";
                cin >> wybor;
                switch (wybor)
                {
                case 1:
                    kopiec.podajRozmiar();
                    kopiec.wypelnij();
                    break;
                case 2:
                    kopiec.wypelnijPlik();
                    break;
                }
            } while (wybor != 1 && wybor != 2);
            while (wybor != 0) {
                cout << "Wybierz funkcje Kopca:" << endl;
                cout << "    1. Dodaj" << endl;
                cout << "    2. Usun" << endl;
                cout << "    3. Wyszukaj" << endl;
                cout << "    4. Wydrukuj kopiec" << endl;
                cout << "    0. Wyjscie" << endl << endl;
                cout << "Wybor: ";
                cin >> wybor;
                switch (wybor) {
                default:
                    cout << "Bledny wybor!" << endl;
                    break;

                case 0:
                    kopiec.usunKopiec();
                    break;

                case 1:
                    cout << "Podaj wartosc: ";
                    cin >> wartosc;
                    czas.czasStart();
                    kopiec.dodaj(wartosc);
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 2:
                    cout << "Podaj pozycje: ";
                    cin >> pozycja;
                    czas.czasStart();
                    kopiec.usunGdzies(pozycja);
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 3:
                    cout << "Podaj pozycje: ";
                    cin >> wartosc;
                    czas.czasStart();
                    kopiec.znajdzElemet(wartosc);
                    czas.czasStop();
                    cout << "Element znajduje sie na " << kopiec.znajdzElemet(wartosc) << " pozycji" << endl;
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;

                case 4:
                    czas.czasStart();
                    kopiec.wyswietl();
                    czas.czasStop();
                    cout << "Czas wykonania: " << czas.czasTrwania() << "ns" << endl;
                    break;
                }
            }
        }
    }
}