#ifndef HASHTAB_HH
#define HASHTAB_HH

#include <iostream>
#include "IAssociative.hh"
using namespace std;

#define N 701

/*!
 * \file HashTab.hh
 *
 *  Plik zawiera implementację tablicy z haszowaniem.
 */

/*!
 * \brief Szablonowa klasa tablicy z haszowaniem
 *
 * Klasa przechowuje elementy w tablicy N-elementowej, w której są
 * umieszczone wskaźniki do listy węzłów w postaci: klucz, wartość.
 * Możliwe jest odwołanie się do wartości za pośrednictwem klucza.
 */
template < typename Object >
class HashTab: public IAssociative<Object>
{
  SList<Object> buckets[N];
public:
  virtual Object & operator[](string klucz);
  unsigned int HashFunction(string klucz);
  unsigned int Insert(Object newItem);
};

template < typename Object >
unsigned int Insert(Object newItem){

}

template < typename Object >
unsigned int HashTab<Object>::HashFunction(string klucz){

  unsigned int x;
  x = klucz.length();
  return x % N;
}


template < typename Object >
Object & HashTab<Object>::operator[](string klucz){

//sprawdzamy, gdzie mamy działać
  unsigned int chosen = Hash(klucz);
//wstawianie
  if( bucket[chosen].IsEmpty() )
    bucket[chosen].AddFront(klucz, )
  return bucket[chosen].Find(klucz)->GetValue();
}

#endif
