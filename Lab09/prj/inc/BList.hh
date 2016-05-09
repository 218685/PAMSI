#ifndef BLIST_HH
#define BLIST_HH

#include <iostream>
#include "IList.hh"
#include "BNode.hh"
using namespace std;

/*!
 * \file  BList.hh
 *
 *  Plik zawiera definicję klasy implementującej listę dwukierunkową.
 */

/*!
 * \brief Szablonowa klasa implementująca listę dwukierunkową
 *
 *  BList jest zbudowana w oparciu o węzły BNode oraz
 *  operacje na wskaźnikach.
 *
 *  BList może przechowywać dowolny typ danych dzięki zastosowaniu
 *  szablonu.
 */
template < typename Object >
class BList : public IList<Object>
{
private:
  BNode<Object> * head; //poczatek listy
  BNode<Object> * tail; //poczatek listy
public:
/*!
 * \brief Konstruktor listy dwukierunkowej
 *
 * Inicjuje listę poprzez ustawienie wskaźnika NULL jako początek
 * (head) tej listy.
 */
  BList();

/*!
 * \brief Destruktor listy dwukierunkowej
 *
 * Usuwa listę poprzez ustawienie wskaźnika NULL jako początek
 * (head) tej listy.
 */
  ~BList();

/*!
 * \brief Metoda zwracająca głowę listy
 *
 * Zwraca wskaźnik do początku listy lub NULL, jeśli lista jest pusta.
 *
 * \return Wskaźnik do głowy listy.
 */
  BNode<Object>* & Head();

  /*!
 * \brief Metoda zwracająca ogon listy
 *
 * Zwraca wskaźnik do końca listy lub NULL, jeśli lista jest pusta.
 *
 * \return Wskaźnik do ogona listy.
 */
  BNode<Object>* & Tail();

/*!
 * \brief Metoda wyszukująca element na liście
 *
 * Implementuje algorytm liniowego przeszukiwania listy.
 *
 * \param[in] k - element do wyszukania
 * \return Wskaźnik do znalezionego elementu lub NULL, gdy nie znaleziono.
 */
  BNode<Object>* Find(Object k);

/*!
 * \brief Metoda sprawdzająca, czy lista jest pusta
 *
 * Sprawdza, czy head wskazuje na coś innego niż NULL.
 * Implementacja metody wirtualnej z interfejsu IList.
 *
 * \return true - jeśli lista jest pusta, false - jeśli nie
 */
  virtual bool IsEmpty();

  virtual void AddFront(const Object newItem);
  virtual void AddBack(const Object newItem);
/*!
 * \brief Metoda dodająca element we wskazane miejsce na liście
 *
 * Alokuje nowy węzeł, dodaje nowy element, dodaje powiązanie tak,
 *
 * \param[in] newItem - element do dodania
 * \param[in] p - docelowa pozycja elementu
 */
  void AddAfter(BNode<Object>* p, const Object newItem);

  /*!
 * \brief Metoda usuwająca wskazany element listy
 *
 * Uaktualnia head, aby wskazywał na kolejny element na liście,
 * po czym usuwa stary węzeł.
 *
 * \param[in] p - element do usunięcia
 */
  const Object& Remove(BNode<Object>* p);
  virtual const Object& RemoveFront();
  virtual const Object& RemoveBack();
  void Print();
};

template <typename Object>
BList<Object>::BList()
  :head (NULL), tail (NULL) {}

template <typename Object>
BList<Object>::~BList(){
  while(!IsEmpty())
    RemoveFront();
}

template <typename Object>
bool BList<Object>::IsEmpty(){

  return (head == NULL) ? true : false;
}

template <typename Object>
BNode<Object>* & BList<Object>::Head(){

  return head;
}

template <typename Object>
BNode<Object>* & BList<Object>::Tail(){

  return tail;
}

template <typename Object>
void BList<Object>::AddFront(const Object newItem){

  BNode<Object>* v = new BNode<Object>;
  v->element() = newItem;
  v->next() = Head();
  v->prev() = NULL;

  Head() = v;

  if(v->next())
    (v->next())->prev() = v;
  else
    Tail() = v;
}

template <typename Object>
void BList<Object>::AddBack(const Object newItem){

  BNode<Object>* v = new BNode<Object>;
  v->element() = newItem;
  v->next() = NULL;
  v->prev() = tail;
  Tail() = v;
  if(v->prev())
    v->prev()->next() = v;
  else
    Head() = v;
}

template <typename Object>
void BList<Object>::AddAfter(BNode<Object>* p, const Object newItem){

  BNode<Object>* v = new BNode<Object>;
  v->element() = newItem;
  v->prev() = p;    // link v do poprzednika
  v->next() = p->next(); //link v do następcy

  p->next()->prev() = v;  //link elementu po p do nowego poprzednika - v
  p->next() =v;              //link p do nowego następcy - v
}

template <typename Object>
const Object& BList<Object>::Remove(BNode<Object>* p){

  if(IsEmpty())
    throw "Lista jest pusta!";
  else{
    Object old = p->element();             //zapamietujemy element usuwany
    if(p->prev())  //jesli jest poprzednik
      p->prev()->next() = p->next();    //link poprzednika p do następcy p
    else    //jesli nie ma poprzednika
      Head() = p->next();
    if(p->next())  //jesli jest nastepnik
      p->next()->prev() = p->prev();    //link następcy p do poprzednika p
    else    //jesli nie ma nastepcy
      Tail() = p->prev();
    //usuwanie wlasciwe podanego elementu
    p->next() = NULL;
    p->prev() = NULL;
    delete p;
    return old;
    }
}

template <typename Object>
const Object& BList<Object>::RemoveFront(){

  return Remove(Head());
}

template <typename Object>
const Object& BList<Object>::RemoveBack(){

  return Remove(Tail());
}

template <typename Object>
BNode<Object>* BList<Object>::Find(Object k){

  BNode<Object>* x = head;
  while(x != NULL && x->element() != k){
    x = x->next();
    }
  return x;
}

template <typename Object>
void BList<Object>::Print(){
  
  BNode<Object>* p = head;

  while(p!=NULL){
    cout << " " << p->element();
    p = p->next();
  }
  cout << endl;
}

#endif
