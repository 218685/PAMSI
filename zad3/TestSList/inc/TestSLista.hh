#ifndef TESTSLISTA_HH
#define TESTSLISTA_HH

#include <iostream>
#include <fstream>
#include "IList.hh"
#include "SNode.hh"
#include "SLista.hh"
#include "IRunnable.hh"
using namespace std;

/*!
 * \file TestSLista.hh
 *
 *  Plik zawiera definicję klasy implementującej listę jednokierunkową
 * oraz interfejs IRunnable
 */

/*!
 * \brief Szablonowa klasa listy jednokierunkowej implementująca IRunnable
 *
 *  TestSLista jest zbudowana w oparciu o węzły SNode oraz
 *  operacje na wskaźnikach.
 *
 *  TestSLista może przechowywać dowolny typ danych dzięki zastosowaniu
 *  szablonu.
 */
template < typename Object >
class TestSLista : public SLista<Object>, public IRunnable<Object>
{
private:
  int ilosc=0;
public:
  //virtual bool Prepare(int rozmiar)=0;
/*!
 * \brief Metoda przygotowująca obiekt do operacji z wykorzystaniem pliku
 *
 * Jeśli list nie jest pusta, metoda ją opróżnia.
 * Następnie wypełnia listę z podanego pliku daną liczbę elementów.
 *
 * \param[in] nazwaPliku - plik do pobrania danych
 * \param[in] rozmiar - liczba elementów do przygotowania
 * \retval true - jeśli przygotowanie się powiodło
 * \retval false - jeśli wystąpił jakiś błąd
 */
  virtual bool PrepareUsingFile(string nazwaPliku, int rozmiar);

/*!
 * \brief Metoda uruchamiająca wyszukiwanie podanego obiektu
 *
 * Wywołuje metodę wyszukującą podany element na liście.
 * Następnie wypisuje na standardowe wyjście "Znaleziono!" bądź "Nie znaleziono!".
 * \param[in] track - element do wyszukania
 * \retval true - operacja zakończyła się niezależnie od tego, czy znaleziono, czy nie
 */
  virtual bool Run(Object track);
};

template <typename Object>
bool TestSLista<Object>::PrepareUsingFile(string nazwaPliku, int rozmiar){

  while(!this->IsEmpty()){
    this->RemoveFront();
    --ilosc;
    }

  fstream plik;
  plik.open( nazwaPliku.c_str() );
  if( !plik.good() )
    return false;

  for(int i=0; i<rozmiar; ++i){
    Object data;
    plik >> data;
    if( plik.good() ){
      this->AddFront(data);
      ++ilosc;
      }
    else
      break; //zakończ wczytywanie danych - wystąpił jakiś błąd (np. nie ma więcej danych w pliku)
    } //for
  cout << "Wczytanych elementów: " << ilosc << endl;
  return true;

}

template <typename Object>
bool TestSLista<Object>::Run(Object track){

  SNode<Object>* znajdek = this->Find(track);
 /* if(znajdek==NULL)
    cout << "Nie znaleziono!" << endl;
  else
    cout << "Znaleziono!" << endl;
*/
  return true;
}

#endif
