#ifndef RBTREE_TEST_HH
#define RBTREE_TEST_HH

#include <iostream>
#include <string>
#include "IRunnable.hh"
#include "RBTree.hh"
using namespace std;

/*!
 * \file  RBTree_Test.hh
 *
 *  Plik zawiera implementację IRunnable w klasie drzewa czerwono-czarnego.
 */

/*!
 * \brief Szablonowa klasa testowego drzewa czerwono-czarnego
 */
template <typename Object>
class RBTree_Test : public RBTree<Object>, public IRunnable<Object>
{
private:
  unsigned problemSize; /*!< n - rozmiar problemu */
  
public:
/*!
 * \brief Metoda przygotowująca obiekt do operacji
 *
 * Metoda wczytuje podaną liczbę losowych elementów do drzewa.
 * Jeśli drzewo jest niepuste, wszystkie elementy są usuwane.
 * \param[in] parametr - liczba elementów do przygotowania;
 * \retval true - jeśli przygotowanie się powiodło
 * \retval false - jeśli wystąpił jakiś błąd
 */
  virtual bool Prepare(Object parametr);
  
 /*!
 * \brief Metoda uruchamiająca proces odczytu
 *
 * Wywołuje metodę Find() dla drzewa dla losowo generowanego
 * elementu.
 *
 * \retval true - jeśli przygotowanie się powiodło
 * \retval false - jeśli wystąpił jakiś błąd
 */
  virtual bool Run();
};

template <typename Object>
bool RBTree_Test<Object>::Prepare(Object parametr){
  
  problemSize = parametr;
 
  this->Clear(this->Root());
  this->Root() = &this->SGuard();
  srand(time( NULL ));
 //wypełnianie drzewa losowymi wartościami
  for(int i=0; i < problemSize; ++i){
    this->Insert(rand() % (10*problemSize) + 1); 
   // this->PrintAll(this->Root());
    //cout << endl;  
  }
  return true;
}

template <typename Object>
bool RBTree_Test<Object>::Run(){
  
  srand(time( NULL ));
  return (this->Find(rand() % (10*problemSize) + 1)) ? true : false;
}
#endif
