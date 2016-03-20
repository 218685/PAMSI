#ifndef KOLEJKA_HH
#define KOLEJKA_HH

#include <iostream>
#include "IQueue.hh"
using namespace std;

/*!
 * \file Kolejka.hh
 *
 *  Plik zawiera implementację interfejsu kolejki
 */

/*!
 * \brief Klasa szablonowa implementująca kolejkę
 *
 *  Kolejka zbudowana jest w oparciu o dynamiczną tablicę.
 *
 *  Kolejka może przechowywać dowolny typ danych dzięki zastosowaniu
 *  szablonu.
 */
template < typename Object >
class Kolejka : public IQueue<Object>
{
private:
  int pojemnosc;
  Object * Tab;
  int f, r;

public:
/*!
 * \brief Konstruktor bezargumentowy kolejki
 *
 * Inicjuje Kolejkę poprzez zaalokowanie tablicy o rozmiarze 1.
 * Ustawia indeksy f (front) i r (rear) na 0.
 */
  Kolejka();

/*!
 * \brief Konstruktor kolejki
 *
 * Inicjuje Kolejkę poprzez zaalokowanie tablicy o rozmiarze
 * podanym w argumencie konstruktora (o ile jest różny od 0).
 * Ustawia indeksy f (front) i r (rear) na 0.
 * \param[in] ile - początkowa pojemność kolejki;
 */
  Kolejka(int ile);

/*!
 * \brief Destruktor kolejki
 *
 * Zwalnia pamięć zajmowaną przez kolejkę.
 * Ustawia wskaźnik tablicy na NULL.
 */
  ~Kolejka();

/*!
 * \brief Metoda sprawdzająca pojemność kolejki
 *
 * Zwraca parametr opisujący pojemność
 * tablicy dynamicznej implementującej kolejkę.
 * \return pojemność kolejki
 */
  int & Pojemnosc(){  return pojemnosc; }

/*!
 * \brief Metoda sprawdzająca, czy kolejka jest pusta
 *
 * Kolejka jest pusta, jeśli wartości indeksów f (front) i r (rear)
 * są sobie równe.
 * \returnval true - jeśli lista jest pusta
 * \returnval false - jeśli nie jest pusta
 */
  virtual bool IsEmpty();

/*!
 * \brief Metoda obliczająca rozmiar kolejki
 *
 * Rozmiar obliczany jest przez odjęcie wartości indeksów f (front) i r (rear).
 * \return liczba elementów w kolejce
 */
  virtual int Size();

/*!
 * \brief Metoda zwracająca pierwszy element kolejki
 *
 * Jeśli kolejka jest pusta, wyrzuca wyjątek.
 * Zwraca element tablicy o indeksie f (front).
 * \return pierwszy element kolejki
 */
  virtual Object& Front();

/*!
 * \brief Metoda dodająca element do kolejki
 *
 * Ustawia element na koniec kolejki
 * - komórka tablicy o indeksie r (rear).
 * Jeśli nie ma już miejsca w kolejce
 * tablica jest powiększana 2 razy.
 * Następnie element zostaje prawidłowo dodany do kolejki,
 * a indeks r zostaje przesunięty o jedno miejsce dalej.
 * \param[in] item - element do dodania
 */
  virtual void Enqueue(Object item);

/*!
 * \brief Metoda usuwająca element kolejki
 *
 * Sprawdza, czy kolejka jest pusta. Jeśli tak, wyrzuca wyjątek.
 * Jeśli nie, usuwa element z początki kolejki o indeksie f (front),
 * a następnie przesuwa indeks f o jedno miejsce dalej.
 *  \return pierwszy element kolejki
 */
  virtual Object& Dequeue();
};

template <typename Object>
Kolejka<Object>::Kolejka(){

  pojemnosc = 1;
  Tab = new Object[pojemnosc];
  f = r = 0;  // pierwszy i ostatni element
  cout << "f konstr: " << f << endl;
  }


template <typename Object>
Kolejka<Object>::Kolejka(int ile){

  if ( ile!=0 )
    pojemnosc = ile;
  else
    pojemnosc = 1;
  Tab = new Object[pojemnosc];
  f = r = 0;
  }

template <typename Object>
Kolejka<Object>::~Kolejka(){

  delete [] Tab;
  Tab = NULL;
}

template <typename Object>
bool Kolejka<Object>::IsEmpty(){

  if (f==r)
    return true;
  else
    return false;
}

template <typename Object>
int Kolejka<Object>::Size(){

  int rozm = r-f;
  return rozm;
}

template <typename Object>
Object& Kolejka<Object>::Front(){

  if(IsEmpty())
    throw "Kolejka jest pusta!";
  return Tab[f];
}

template <typename Object>
void Kolejka<Object>::Enqueue(Object item){

  if(Pojemnosc() > Size()){
    Tab[r] = item;
    r++;
    cout << "dodano: " << Tab[r-1] << endl;
    cout << "po ostanim: " << r << endl;
    }
  else{
    Pojemnosc() = Pojemnosc()*2;    // podwajamy pojemnosc
    int *temp = new int [Pojemnosc()];  // tworzymy nowa tablice
    copy(Tab, Tab+(Pojemnosc()/2), temp);   //kopiujemy wszystkie elementy starej do nowej
    delete [] Tab;                // usuwamy stara tablice
    temp[r] = item;
    r++;
    Tab = temp;
    cout << "dodano: " << Tab[r-1] << endl;
  }

}

template <typename Object>
Object& Kolejka<Object>::Dequeue(){

  if(IsEmpty())
    throw "Kolejka jest pusta!";
  else{
    Object temp = Tab[f];  // zapisujemy pierwszy element
    f++;
    return temp;
    }
}

#endif
