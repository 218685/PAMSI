#ifndef ILIST_HH
#define ILIST_HH

#include <iostream>
using namespace std;

/*!
 * \file  IList.hh
 *
 *  Plik zawiera interfejs listy jednokierunkową
 */

/*!
 * \brief Interfejs listy jednokierunkowej
 *
 *  Definiuje ADT dla listy jednokierunkowej.
 *
 *  Lista może przechowywać dowolny typ danych dzięki zastosowaniu
 *  szablonu.
 */
template < typename Object >
class IList
{
public:
/*!
 * \brief Metoda sprawdzająca, czy lista jest pusta
 *
 * \returnval true - jeśli lista jest pusta
 * \returnval truefalse - jeśli nie jest pusta
 */
  virtual bool IsEmpty() = 0;

/*!
 * \brief Metoda zwracająca pierwszy element listy
 *
 * \return pierwszy element listy
 */
  virtual const Object& Front() = 0;

/*!
 * \brief Metoda dodająca element na początek listy
 *
 *
 * \param[in] newItem - element do dodania
 */
  virtual void AddFront(const Object newItem) = 0;

/*!
 * \brief Metoda usuwająca element z początku listy
 *
 */
  virtual void RemoveFront() = 0;

};

#endif
