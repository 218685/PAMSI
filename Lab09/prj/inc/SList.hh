#ifndef SLIST_HH
#define SLIST_HH

#include <iostream>
#include "IList.hh"
#include "Node.hh"
using namespace std;

/*!
 * \file  SList.hh
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
class SList : public IList<Object>
{
private:
  Node<Object> * head; /*!< początek listy */
public:
/*!
 * \brief Konstruktor listy jednokierunkowaj
 *
 * Inicjuje SListę poprzez ustawienie wskaźnika NULL jako początek
 * (head) tej listy.
 */
  SList();

/*!
 * \brief Destruktor listy jednokierunkowaj
 *
 * Usuwa listę poprzez zwalnianie pamięci kolejnych początkowych węzłów.
 */
  ~SList();

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
 * \return element pierwszego węzła listy
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
 * \brief Metoda dodająca nowy węzeł na początek listy
 *
 * Alokuje nowy węzeł, przypisuje podane klucz i wartość,
 * dodaje powiązanie tak, aby węzeł wskazywał na stary head,
 * uaktualnia head.
 *
 * \param[in] newKey - klucz do dodania
 * \param[in] newItem - wartość do dodania
 */
  void AddFront(const string newKey, const Object newItem);

/*!
 * \brief Metoda usuwająca element z początku listy
 *
 * Uaktualnia head, aby wskazywał na kolejny element na liście,
 * po czym usuwa stary węzeł.
 *
 * \param[in] newItem - element do dodania
 */
  virtual void RemoveFront();

/*!
 * \brief Metoda zwracająca głowę listy
 *
 * Zwraca wskaźnik do początku listy lub NULL, jeśli lista jest pusta.
 *
 * \return Wskaźnik do głowy listy.
 */
  Node<Object>* Head();

/*!
 * \brief Metoda usuwająca węzeł o podanym kluczu
 *
 * Znajduje węzeł o podanym kluczu. Uaktualnia wskaźnik poprzednika
 * na następny element listy.
 * Usuwa go, zapamiętują wartość w nim przechowywaną.
 * \param[in] key - klucz elementu do usunięcia
 */
  Object Remove(string key);

/*!
 * \brief Metoda wypisująca zawartość listy na standardowe wyjście
 */
  void Print();

/*!
 * \brief Metoda wyszukująca element na liście
 *
 * Implementuje algorytm liniowego przeszukiwania listy.
 *
 * \param[in] k - element do wyszukania
 * \return Wskaźnik do znalezionego elementu lub NULL, gdy nie znaleziono.
 */
  Node<Object>* Find(Object k);

/*!
 * \brief Metoda wyszukująca klucz na liście
 *
 * Liniowo przeszukuje listę porównując kolejne klucze z podanym.
 *
 * \param[in] key - klucz do wyszukania
 * \return Wskaźnik do znalezionego elementu lub NULL, gdy nie znaleziono.
 */
  Node<Object>* Find(string key);

/*!
 * \brief Wyszukuje lub tworzy klucz na liście
 *
 * Liniowo przeszukuje listę porównując kolejne klucze z podanym.
 * Jeśli klucza nie znaleziono, na początek listy
 * dodawany jest nowy węzeł o podanym kluczu. Jego wartość (domyślnie równą 0)
 * można ustawić poprzez operację przypisania (za pomocą operatora []).
 *
 * \param[in] key - klucz do wyszukania lub utworzenia
 * \return Wskaźnik do znalezionego lub nowoutworzonego elementu.
 */
  Node<Object>* FindOrAdd(string key);
};

template <typename Object>
SList<Object>::SList()
  :head (NULL) {}

template <typename Object>
SList<Object>::~SList(){

  while(!IsEmpty())
    RemoveFront();
}

template <typename Object>
bool SList<Object>::IsEmpty(){

  if(head == NULL)
    return true;
  else
    return false;
}

template <typename Object>
Node<Object>* SList<Object>::Head(){

  if(!IsEmpty())
    return head;
  else
    return NULL;
}

template <typename Object>
const Object& SList<Object>::Front(){

  if(!IsEmpty())
    return head->GetValue();
  else
    throw "Lista jest pusta!";
}

template <typename Object>
void SList<Object>::AddFront(const Object newItem){

  Node<Object>* v = new Node<Object>;
  v->SetValue(newItem);
  v->SetNext(head);
  head = v;
}

template <typename Object>
void SList<Object>::AddFront(const string newKey, const Object newItem){

  Node<Object>* v = new Node<Object>;
  v->SetKey(newKey);
  v->SetValue(newItem);
  v->SetNext(head);
  head = v;
}

template <typename Object>
void SList<Object>::RemoveFront(){

  if(IsEmpty())
    throw "Lista jest pusta!";
  else{
    Node<Object> * old = head;    //zapamietujemy stary head
    head = old->GetNext();        // bierzemy nastepny element jako head
    delete old;     //usuwamy starego heada
  }
}

template <typename Object>
Object SList<Object>::Remove(string key){

  if(IsEmpty())
    return 0;
  else{
    Node<Object>* x = head;
    Node<Object>* p = x;
    while(x!=NULL && x->GetKey()!= key){
      p = x;
      x = x->GetNext();
      }
    p->SetNext(x->GetNext());

    Object old_value = x->GetValue();
    delete x;
    x = NULL;
    return old_value;

  }
}

template <typename Object>
void SList<Object>::Print(){
  if(!IsEmpty())
    for(Node<Object>* p = head; p; p = p->GetNext())
      cout <<'\t'<<p->GetKey()<<'\t'<<'\t'<<p->GetValue()<< endl;
}

template <typename Object>
Node<Object>* SList<Object>::Find(Object k){

  Node<Object>* x = head;
  while(x!=NULL && x->GetValue()!= k)
    x = x->GetNext();
  if(x == NULL)
    cout << "znaleziono NULL" << endl;
  return x;
}

template <typename Object>
Node<Object>* SList<Object>::Find(string key){

  Node<Object>* x = head;
  while(x!=NULL && x->GetKey()!=key)
    x = x->GetNext();

  return x;
}

template <typename Object>
Node<Object>* SList<Object>::FindOrAdd(string key){

  Node<Object>* x = head;
  while(x!=NULL && x->GetKey()!= key)
    x = x->GetNext();
  if(x==NULL){
    x = new Node<Object>;
    x->SetKey(key);
    x->SetNext(head);
    head = x;
    }
  return x;
}

#endif
