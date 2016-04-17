#ifndef HASHTAB_HH
#define HASHTAB_HH

#include <iostream>
#include <cmath>
#include <bitset>
#include <functional>
#include "IAssociative.hh"
#include "SList.hh"
using namespace std;

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
  unsigned N; /*!< pojemność tablicy */
  SList<Object>* buckets = NULL;  /*!< docelowo tablica dynamiczna N list */
public:
/*!
 * \brief Konstruktor tablicy z haszowaniem
 *
 * Inicjuje tablicę z haszowaniem poprzez zaolokowanie 5-elementowej
 * tablicy list jednokierunkowych, w których można przechowywać elementy
 * w postaci: (klucz (łańcuch znakowy), wartość).
 */
  HashTab();

/*!
 * \brief Destruktor tablicy z haszowaniem
 *
 * Zwalnia pamięć zajmowaną przez tablicę i ustawia wskaźnik na NULL.
 */
  ~HashTab();

/*!
 * \brief Realokuje tablicę z haszowaniem dla podanej liczby elementów
 *
 * Zwalnia pamięć zajmowaną przez starą tablicę, jeśli istniała wcześniej.
 * Alokuje nową tablicę o pojemności 75% podanej wartości + 1.
 * \param[in] ile - liczba elementów, które mają być docelowo przechowywane w tablicy
 */
  void ResetBuckets(int ile);

/*!
 * \brief Funkcja skrótu
 *
 * Oblicz indeks tablicy, do którego trafi element o podanym kluczu.
 * Zamienia łańcuch znakowy na kod ASCII, jednocześnie wykonując działania
 * arytmetyczne z dobranymi wartościami zmiennej a i stałej b (w tym dzielenie modulo
 przez pojemność tablicy.
 * Dzięki temu funkcja zapewnia równomierny rozkład kluczy w tablicy z haszowaniem.
 * Jeśli w wyniku obliczeń indeks będzie ujemny, funkcja zwróci wynik dodawania
 ujemnego indeksu i pojemności tablicy.
 *
 * \param[in] klucz - łańcuch znakowy, dla którego ma zostać wyliczony indeks
 */
  unsigned HashFunction(string klucz);

/*!
 * \brief Przeciążenie operatora indeksującego tablicy z haszowaniem
 *
 * Umożliwia odczyt i zapis do tablicy z haszowaniem elementu o podanym kluczu.
 * Wywołuje metodę skrótu, a następnie szuka elementu znajdującego się pod podanym kluczem
 * na liście w otrzymanym przez funkcję skrótu indeksie.
 *
 * \param[in] klucz - łańcuch znakowy do dodania lub odczytania
 * \return Element pod wskazanym kluczem.
 */
  virtual Object & operator[](string klucz);

/*!
 * \brief Dodaje element o podanym kluczu do tablicy z haszowaniem
 *
 * Wywołuje funkcję skrótu, a następnie wstawia nowy element
 * do tablicy pod otrzymanym indeksem.
 * Jeśli otrzymany indeks jest już zajęty, element zostaje wstawiony na początek
 * listy przechowywanej pod nim.
 *
 * \param[in] klucz - łańcuch znakowy do dodania
 * \param[in] newItem - wartość dostępna pod podanym kluczem
 * \return Indeks w tablicy, pod którym znajduje się podany klucz.
 */
  virtual unsigned Insert(string klucz, Object newItem);

/*!
 * \brief Szuka elementu o podanym kluczu
 *
 * Wywołuje funkcję skrótu, a następnie przeszukuje listę pod otrzymanym indeksem.
 * Zwraca element dostępny pod podanym kluczem (jeśli nie ma wartości, zwraca 0).
 *
 * \param[in] klucz - łańcuch znakowy do wyszukania
 * \return Element pod wskazanym kluczem.
 */
  virtual Object Search(string klucz);

/*!
 * \brief Usuwa element o podanym kluczu
 *
 * Usuwa element z tablicy. Zwraca wartość pod podanym kluczem.
 *
 * \param[in] klucz - łańcuch znakowy do wyszukania
 * \return Wartość pod wskazanym kluczem.
 */
  virtual Object Delete(string klucz);

/*!
 * \brief Drukuje całą tablicę z haszowaniem na standardowe wyjście
 *
 * Elementy są wypisywane wg kolejnych indeksów tablicy tylko,
 * jeśli dany indeks jest zajęty.
 */
  void PrintAll();
};

template < typename Object >
HashTab<Object>::HashTab(){

  N = 5;
  buckets = new SList<Object>[N];
}

template < typename Object >
HashTab<Object>::~HashTab(){

  if(buckets!=NULL){
    delete[] buckets;
    buckets = NULL;
    }
}

template < typename Object >
void HashTab<Object>::ResetBuckets(int ile){

  if(buckets!=NULL){
    delete[] buckets;
    buckets = NULL;
    }

  N = 3*ile/4 + 1;
  buckets = new SList<Object>[N];
}

template < typename Object >
unsigned HashTab<Object>::HashFunction(string klucz){

/*
  unsigned h=0;

  for( int i = 0; i < klucz.length(); ++i )
     h += ( int ) klucz[ i ] ;

  return h % N;
*/

  unsigned h=0;

  int a = 31415, b = 27183;
  for(int i = 0; i<klucz.length(); ++i) {
    h = (a*h + klucz[i]) % N;
    a = a*b % (N-1);
    }

  if(h<0)
    return h+N;
  else
    return h;
}

template < typename Object >
Object & HashTab<Object>::operator[](string klucz){
//sprawdzamy, gdzie mamy działać
  unsigned chosen = HashFunction(klucz);

  return buckets[chosen].FindOrAdd(klucz)->GetValue();
}

template < typename Object >
unsigned HashTab<Object>::Insert(string klucz, Object newItem){

  unsigned chosen = HashFunction(klucz);
//wstawianie
  buckets[chosen].AddFront(klucz, newItem);

  return chosen;
}

template < typename Object >
Object HashTab<Object>::Search(string klucz){

  unsigned chosen = HashFunction(klucz);
  Node<Object>* found = buckets[chosen].Find(klucz);

  return (found!=NULL) ? found->GetValue() : 0;
}

template < typename Object >
Object HashTab<Object>::Delete(string klucz){

  unsigned chosen = HashFunction(klucz);
  return buckets[chosen].Remove(klucz);
}

template < typename Object >
void HashTab<Object>::PrintAll(){

  for(int i=0; i<N; ++i){
    if(buckets[i].Head()!=NULL)
      cout << " Bucket nr " << i << endl;
    buckets[i].Print();
    }
}
#endif
