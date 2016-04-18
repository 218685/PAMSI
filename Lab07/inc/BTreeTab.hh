#ifndef BTREETAB_HH
#define BTREETAB_HH

#include <iostream>
#include "IBinaryTree.hh"
using namespace std;

template < typename Object >
class BTreeTab: public IBinaryTree <Object>
{
protected:
  unsigned cap = 2;
  unsigned rozm = 0;
  Object* tab;
public:
  BTreeTab() { tab = new Object [cap]; };
  BTreeTab(int ile);
  ~BTreeTab() { delete [] tab; tab = NULL; };
  unsigned& Pojemnosc(){ return cap;  };
  unsigned& Rozmiar(){ return rozm; };
  Object* Zwieksz2Razy();

  virtual void Insert(const Object newItem);
  virtual Object& Remove(Object newItem);
  virtual bool IsEmpty();
  virtual Object& Root();

  unsigned Parent(unsigned i);
  unsigned Left(unsigned i);
  unsigned Right(unsigned i);
  virtual void PreOrder(unsigned i);
  virtual void InOrder(unsigned i);
  virtual void PostOrder(unsigned i);
  void PrintAll();
};

template < typename Object >
BTreeTab<Object>::BTreeTab(int ile){

  if(ile!=0){
    cap = ile;
    tab = new Object [ile];
    }
  else
    tab = new Object [cap];
}

template < typename Object >
bool BTreeTab<Object>::IsEmpty(){

  return (!tab[1]) ? true : false;
}

template < typename Object >
unsigned BTreeTab<Object>::Parent(unsigned i){
  return i/2;
}

template < typename Object >
unsigned BTreeTab<Object>::Left(unsigned i){
  return 2*i;
}

template < typename Object >
unsigned BTreeTab<Object>::Right(unsigned i){
  return 2*i+1;
}

template < typename Object >
Object& BTreeTab<Object>::Root(){

  if(tab[1])
    return tab[1];
  else
    return 0;
}

template < typename Object >
void BTreeTab<Object>::Insert(const Object newItem){

  if(Pojemnosc() == Rozmiar())
    tab = Zwieksz2Razy();   //jesli nie ma miejsca, powiekszamy tablicę

  if(IsEmpty())
    tab[++Rozmiar()] = newItem;
  else{
    unsigned j = 1;
    while(tab[j]){
      if(newItem <= tab[j])
        j = Left(j);
      else
        j = Right(j);
    }
    tab[j] = newItem;
    ++Rozmiar();
  }
}

template < typename Object >
Object& BTreeTab<Object>::Remove(Object newItem){

  if(Rozmiar()==0)    //jesli kopiec jest pusty nic nie rób
    throw "Kopiec jest pusty!";

  Object tmp = tab[1];      //zapamietujem żeby zwrócić
  tab[1] = tab[Rozmiar()];    //zamieniamy ostatni z korzeniem, usuwając korzeń
  --Rozmiar();                // zmiejszamy rozmiar
  cout << "rozm " << Rozmiar() << endl;
  DownHeap();                 //przywracamy wlasciwosc kopca
  return tmp;
}

template < typename Object >
Object* BTreeTab<Object>::Zwieksz2Razy()
{
  Pojemnosc() = Pojemnosc()*2;    // podwajamy pojemnosc
  Object *temp = new Object [Pojemnosc()];  // tworzymy nowa tablice
  copy(tab, tab+(Pojemnosc()/2), temp);   //kopiujemy wszystkie elementy starej do nowej
  delete [] tab;                // usuwamy stara tablice
  return temp;                  // zwracamy nowa powiekszona tablice
}

void BTreeTab<Object>::PreOrder(unsigned i){

  if(!tab[1])
    cout << "BT: Pusto!" << endl;
  if(tab[i])
    cout << tab[i] << endl;
  if(tab[Left(i)] )
    PreOrder(Left(i));
  if(tab[Right(i)])
    PreOrder(Right(i));
}

void BTreeTab<Object>::InOrder(unsigned i){

  if(!tab[1])
    cout << "BT: Pusto!" << endl;
  if(tab[Left(i)] )
    PreOrder(Left(i));
  if(tab[i])
    cout << tab[i] << endl;
  if(tab[Right(i)])
    PreOrder(Right(i));
}

void BTreeTab<Object>::PostOrder(unsigned i){

  if(!tab[1])
    cout << "BT: Pusto!" << endl;

  if(tab[Left(i)] )
    PreOrder(Left(i));
  if(tab[Right(i)])
    PreOrder(Right(i));
  if(tab[i])
    cout << tab[i] << endl;
}

template < typename Object >
void BTreeTab<Object>::PrintAll() {

  if(!tab[1])
    cout << "BTree: Pusto!";
  else
    for(int j = 1; j < Rozmiar(); ++j)
      cout << tab[j] << "  ";

  cout << endl;
}

#endif
