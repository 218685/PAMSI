#ifndef STOS_HH
#define STOS_HH

#include "IStack.hh"
using namespace std;

/*!
 * \file Stos.hh
 *
 *  Plik zawiera implementację interfejsu stosu
 */

/*!
 * \brief Klasa szablonowa implementująca stos
 *
 *  Stos zbudowany jest w oparciu o dynamiczną tablicę.
 *
 *  Stos może przechowywać dowolny typ danych dzięki zastosowaniu
 *  szablonu.
 */
template < typename Object >
class Stos : public IStack<Object>
{
private:
  int pojemnosc;
  Object * Tab;
  int top;

public:
/*!
 * \brief Konstruktor bezargumentowy stosu
 *
 * Inicjuje stos poprzez zaalokowanie tablicy o rozmiarze 1.
 * Ustawia indeks top na -1.
 */
  Stos();

/*!
 * \brief Konstruktor stosu
 *
 * Inicjuje stos poprzez zaalokowanie tablicy o rozmiarze
 * podanym w argumencie konstruktora (o ile jest różny od 0).
 * Ustawia indeks top na -1.
 * \param[in] ile - początkowa pojemność kolejki;
 */
  Stos(int ile);

/*!
 * \brief Destruktor stosu
 *
 * Zwalnia pamięć zajmowaną przez stosu.
 * Ustawia wskaźnik tablicy dynamicznej na NULL.
 */
  ~Stos();

/*!
 * \brief Metoda sprawdzająca pojemność stosu
 *
 * Zwraca parametr opisujący pojemność
 * tablicy dynamicznej implementującej stos.
 * \return pojemność stosu
 */
  int & Pojemnosc(){  return pojemnosc; }

/*!
 * \brief Metoda sprawdzająca, czy stos jest pusty
 *
 * Jeśli indeks top<0, stos jest pusty.
 * W przeciwnym wypadku, stos nie jest pusty.
 * \returnval true - jeśli stos jest pusty
 * \returnval false - jeśli stos nie jest pusty
 */
  virtual bool IsEmpty();

/*!
 * \brief Metoda obliczająca rozmiar stosu
 *
 * Rozmiar obliczany jest przez działanie 'top+1'.
 * \return liczba elementów na stosie
 */
  virtual int Size();

/*!
 * \brief Metoda zwracająca wierzchołek stosu
 *
 * Jeśli stos jest pusty, wyrzuca wyjątek.
 * Zwraca element tablicy o indeksie top.
 * \return element na wierzchu stosu
 */
  virtual Object Top();

/*!
 * \brief Metoda dodająca element na stos
 *
 * Wrzuca element na wierzchołek stosu.
 * Indeks top zostaje przesunięty o jedno miejsce dalej.
 * Jeśli nie ma już miejsca na stosie
 * tablica jest powiększana 2 razy.
 * Następnie element zostaje prawidłowo wrzucony na stos,
 * a indeks top zostaje przesunięty o jedno miejsce dalej.
 * \param[in] item - element do dodania
 */
  virtual void Push(Object item);

/*!
 * \brief Metoda zrzucająca element ze stosu
 *
 * Jeśli stos jest pusty, wyrzuca wyjątek.
 * Zwraca element tablicy o indeksie top.
 * Zmniejsza indeks top o 1.
 * \return element na wierzchu stosu
 */
  virtual Object Pop();

};


template <typename Object>
Stos<Object>::Stos(){

  pojemnosc = 1;
  Tab = new Object[pojemnosc];
  top = -1;
  }


template <typename Object>
Stos<Object>::Stos(int ile){

  if ( ile!=0 )
    pojemnosc = ile;
  else
    pojemnosc = 1;
  Tab = new Object[pojemnosc];
  top = -1;  //działa jako indeks tablicy
  }


template <typename Object>
Stos<Object>::~Stos(){

  delete [] Tab;
  Tab = NULL;
}

template <typename Object>
bool Stos<Object>::IsEmpty(){

  if (top<0)
    return true;
  else
    return false;
}

template <typename Object>
int Stos<Object>::Size(){

  int rozm = top+1;
  return rozm;

}

template <typename Object>
Object Stos<Object>::Top(){

  if(IsEmpty()){
    cerr << "Stos jest pusty!";
    return 0;
  }
  else
    return Tab[top];
}

template <typename Object>
void Stos<Object>::Push(Object item){

  if(Pojemnosc() > Size()){
    top++;
    Tab[top] = item;
    }
  else{
    Pojemnosc() = Pojemnosc()*2;    // podwajamy pojemnosc
    Object* temp = new Object [Pojemnosc()];  // tworzymy nowa tablice
    copy(Tab, Tab+(Pojemnosc()/2), temp);   //kopiujemy wszystkie elementy starej do nowej
    delete [] Tab;                // usuwamy stara tablice
    Tab = temp;
    Tab[top] = item;
  }

}

template <typename Object>
Object Stos<Object>::Pop(){

  if(IsEmpty()){
    cerr << "Stos jest pusty!";
    return 0;
    }
  else
    return Tab[top--];
}



#endif
