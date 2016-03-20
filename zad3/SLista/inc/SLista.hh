#ifndef SLISTA_HH
#define SLISTA_HH

#include <iostream>
#include "IList.hh"
#include "SNode.hh"
using namespace std;

/*!
 * \file  SLista.hh
 *
 *  Plik zawiera definicję klasy implementującej listę jednokierunkową.
 */

/*!
 * \brief Szablonowa klasa implementująca listę jednokierunkową
 *
 *  SLista jest zbudowana w oparciu o węzły SNode oraz
 *  operacje na wskaźnikach.
 *
 *  SLista może przechowywać dowolny typ danych dzięki zastosowaniu
 *  szablonu.
 */
template < typename Object >
class SLista : public IList<Object>
{
private:
  SNode<Object> * head; //poczatek listy
public:

/*!
 * \brief Konstruktor listy jednokierunkowaj
 *
 * Inicjuje SListę poprzez ustawienie wskaźnika NULL jako początek
 * (head) tej listy.
 */
  SLista();

/*!
 * \brief Destruktor listy jednokierunkowaj
 *
 * Usuwa SListę poprzez ustawienie wskaźnika NULL jako początek
 * (head) tej listy.
 */
  ~SLista();

/*!
 * \brief Metoda zwracająca głowę listy
 *
 * Zwraca wskaźnik do początku listy lub NULL, jeśli lista jest pusta.
 *
 * \return Wskaźnik do głowy listy.
 */
  SNode<Object>* Head();

/*!
 * \brief Metoda wyszukująca element na liście
 *
 * Implementuje algorytm liniowego przeszukiwania listy.
 *
 * \param[in] k - element do wyszukania
 * \return Wskaźnik do znalezionego elementu lub NULL, gdy nie znaleziono.
 */
  SNode<Object>* Find(Object k);

/*!
 * \brief Metoda sprawdzająca, czy lista jest pusta
 *
 * Sprawdza, czy head wskazuje na coś innego niż NULL.
 * Implementacja metody wirtualnej z interfejsu IList.
 *
 * \return true - jeśli lista jest pusta, false - jeśli nie
 */
  virtual bool IsEmpty();

/*!
 * \brief Metoda zwracająca pierwszy element listy
 *
 *  Sprawdza, czy lista jest pusta i zwraca dane pierwszego węzła listy.
 *  Jeśli lista jest pusta, wyrzuca wyjątek.
 *
 * \return dane pierwszego węzła listy
 */
  virtual const Object& Front();

/*!
 * \brief Metoda dodająca element na początek listy
 *
 * Alokuje nowy węzeł, dodaje nowy element, dodaje powiązanie tak,
 * aby węzeł wskazywał na stary head, uaktualnia head.
 *
 * \param[in] newItem - element do dodania
 */
  virtual void AddFront(const Object newItem);

/*!
 * \brief Metoda usuwająca element z początku listy
 *
 * Uaktualnia head, aby wskazywał na kolejny element na liście,
 * po czym usuwa stary węzeł.
 *
 * \param[in] newItem - element do dodania
 */
  virtual void RemoveFront();
  void printl();
};

template <typename Object>
void SLista<Object>::printl()
{
  if(!IsEmpty())
    for(SNode<Object>* p = head; p; p = p->GetNext())
      cout << p->GetElement() << " ";
}

template <typename Object>
SNode<Object>* SLista<Object>::Find(Object k){

  SNode<Object>* x = head;
  while(x!=NULL && x->GetElement()!= k){
    x = x->GetNext();
    }
  return x;
}

template <typename Object>
SLista<Object>::SLista()
  :head (NULL) {}

template <typename Object>
SLista<Object>::~SLista(){

  while(!IsEmpty())
    RemoveFront();
}

template <typename Object>
bool SLista<Object>::IsEmpty(){

  if(head == NULL)
    return true;
  else
    return false;
}

template <typename Object>
SNode<Object>* SLista<Object>::Head(){

  if(!IsEmpty())
    return head;
  else
    return NULL;
}

template <typename Object>
const Object& SLista<Object>::Front(){

  if(!IsEmpty())
    return head->GetElement();
  else
    throw "Lista jest pusta!";
}

template <typename Object>
void SLista<Object>::AddFront(const Object newItem){

  SNode<Object>* v = new SNode<Object>;
  v->SetElement(newItem);
  v->SetNext(head);
  head = v;
}

template <typename Object>
void SLista<Object>::RemoveFront(){

  if(IsEmpty())
    throw "Lista jest pusta!";
  else{
    SNode<Object> * old = head;    //zapamietujemy stary head
    head = old->GetNext();        // bierzemy nastepny element jako head
    delete old;     //usuwamy starego heada
  }
}

#endif
