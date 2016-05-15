#ifndef IBLIST_HH
#define IBLIST_HH

#include <iostream>
using namespace std;

/*!
 * \file  IBList.hh
 *
 *  Plik zawiera interfejs listy dwukierunkową
 */

/*!
 * \brief Interfejs listy dwukierunkowej
 *
 *  Definiuje ADT dla listy dwukierunkowej.
 *
 *  Lista może przechowywać dowolny typ danych dzięki zastosowaniu
 *  szablonu.
 */
template < typename Object >
class IBList
{
public:
/*!
 * \brief Metoda sprawdzająca, czy lista jest pusta
 *
 * \returnval true - jeśli lista jest pusta
 * \returnval truefalse - jeśli nie jest pusta
 */
  virtual bool IsEmpty() = 0;

  virtual void AddFront(const Object newItem) = 0;
  virtual void AddBack(const Object newItem) = 0;

  virtual const Object RemoveFront() = 0;
  virtual const Object RemoveBack() = 0;
};

#endif
