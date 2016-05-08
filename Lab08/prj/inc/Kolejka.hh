#ifndef KOLEJKA_HH
#define KOLEJKA_HH

#include <iostream>
#include "IQueue.hh"
#include "SNode.hh"
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
  SNode<Object>* head;
  SNode<Object>* tail;
public:
/*!
 * \brief Konstruktor bezargumentowy kolejki
 *
 * Inicjuje Kolejkę poprzez zaalokowanie tablicy o rozmiarze 1.
 * Ustawia indeksy f (front) i r (rear) na 0.
 */
  Kolejka();

/*!
 * \brief Destruktor kolejki
 *
 * Zwalnia pamięć zajmowaną przez kolejkę.
 * Ustawia wskaźnik tablicy na NULL.
 */
  ~Kolejka();

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
 * \brief Metoda zwracająca pierwszy element kolejki
 *
 * Jeśli kolejka jest pusta, wyrzuca wyjątek.
 * Zwraca element tablicy o indeksie f (front).
 * \return pierwszy element kolejki
 */
  virtual Object Front();

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
  virtual Object Dequeue();
};

template < typename Object >
Kolejka<Object>::Kolejka(){

  head = tail = NULL;
}

template <typename Object>
Kolejka<Object>::~Kolejka(){

  while(head)
    Dequeue();
}

template <typename Object>
bool Kolejka<Object>::IsEmpty(){

  return (head==NULL) ? true : false;
}

template <typename Object>
Object Kolejka<Object>::Front(){

  if(head)
    return head->GetElement();
  else
    return 0;
}

template <typename Object>
void Kolejka<Object>::Enqueue(Object item){

  SNode<Object>* v = new SNode<Object>;
  v->SetNext(NULL);
  v->SetElement(item);
  if(tail!=NULL)
    tail->SetNext(v);
  else
    head = v;
    tail = v;
}

template <typename Object>
Object Kolejka<Object>::Dequeue(){

  if(head!=NULL){
    SNode<Object>* v = head;
    Object item = head->GetElement();
    head = head->GetNext();
    if(head==NULL)
      tail = NULL;
    delete v;
    return item;
  }
  return 0;
}


#endif
