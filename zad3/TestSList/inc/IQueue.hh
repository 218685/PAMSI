#ifndef IQUEUE_HH
#define IQUEUE_HH

#include <iostream>
using namespace std;

/*!
 * \file IQueue.hh
 *
 *  Plik zawiera interfejs kolejki
  */

/*!
 * \brief Klasa modelująca interfejs kolejki
 *
 *  Definiuje ADT dla kolejki.
 *
 *  Kolejka może przechowywać dowolny typ danych dzięki zastosowaniu
 *  szablonu.
 */
template < typename Object >
class IQueue
{
public:

/*!
 * \brief Metoda sprawdzająca, czy lista jest pusta
 *
 * \returnval true - jeśli lista jest pusta
 * \returnval false - jeśli nie jest pusta
 */
  virtual bool IsEmpty() = 0;

/*!
 * \brief Metoda obliczająca rozmiar kolejki
 *
 * \return liczba elementów w kolejce
 */
  virtual int Size() = 0;

/*!
 * \brief Metoda zwracająca pierwszy element kolejki
 *
 * \return pierwszy element kolejki
 */
  virtual Object& Front() = 0;

/*!
 * \brief Metoda dodająca element do kolejki
 *
 * Ustawia element na koniec kolejki.
 * \param[in] item - element do dodania
 */
  virtual void Enqueue(Object item) = 0;

/*!
 * \brief Metoda usuwająca element kolejki
 *
 *  Usuwa element z początki kolejki.
 *  \return pierwszy element kolejki
 */
  virtual Object& Dequeue() = 0;
};

#endif
