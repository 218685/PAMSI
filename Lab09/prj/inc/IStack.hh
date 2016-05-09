#ifndef ISTACK_HH
#define ISTACK_HH

#include <iostream>
using namespace std;

/*!
 * \file  IStack.hh
 *
 *  Plik zawiera interfejs stosu
 */

/*!
 * \brief Klasa szablonowa modelująca interfejs stosu
 *
 *  Definiuje ADT dla stosu.
 *
 *  Stos może przechowywać dowolny typ danych dzięki zastosowaniu
 *  szablonu.
 */
template < typename Object >
class IStack
{
public:

/*!
 * \brief Metoda sprawdzająca, czy stos jest pusty
 *
 * \returnval true - jeśli stos jest pustay
 * \returnval false - jeśli stos nie jest pusty
 */
  virtual bool IsEmpty() = 0;

/*!
 * \brief Metoda obliczająca rozmiar stosu
 *
 * \return liczba elementów na stos
 */
  virtual int Size() = 0;

/*!
 * \brief Metoda zwracająca wierzchołek stosu
 *
 * \return element na wierzchu stosu
 */
  virtual Object Top() = 0;

/*!
 * \brief Metoda dodająca element na stos
 *
 * Wrzuca element na wierzchołek stosu.
 * \param[in] item - element do dodania
 */
  virtual void Push(Object item) = 0;

/*!
 * \brief Metoda zrzucająca element ze stosu
 *
 * Usuwa wierzchołek ze stosu i zwraca jego wartość.
 * \return element na wierzchu stosu
 */
  virtual Object Pop() = 0;
};

#endif
