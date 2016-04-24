#ifndef IRUNNABLE_HH
#define IRUNNABLE_HH

#include <iostream>
using namespace std;

/*!
 * \file IRunnable.hh
 *
 *  Plik zawiera interfejs obiektu,
 *  który można poddawać pomiarom czasu działania.
 */

/*!
 * \brief Klasa szablonowa modelująca interfejs "Biegacza"
 *
 * Klasa jest abstrakcyjnym uogólnieniem obiektu, na którym można wykonać
 * zdefiniowane operacje, którym z kolei można zmierzyć czas wykonywania.
 *
 */
template < typename Object >
class IRunnable
{
public:
/*!
 * \brief Metoda przygotowująca obiekt do operacji
 *
 * \param[in] rozmiar - liczba elementów do przygotowania;
 *
 * \retval true - jeśli przygotowanie się powiodło
 * \retval false - jeśli wystąpił jakiś błąd
 */
  virtual bool Prepare(Object parametr) = 0;

/*!
 * \brief Metoda uruchamiająca zdefiniowaną operację
 *
 * \param[in] track - parametr wykonania operacji
 * \retval true - jeśli operacja zakończyła się pomyślnie
 * \retval false - jeśli wystąpił jakiś błąd
 */
  virtual bool Run() = 0;
};

#endif
