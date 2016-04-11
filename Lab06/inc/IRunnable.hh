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
protected:
  Object parametr;
public:
/*!
 * \brief Metoda zwracająca zdefiniowany parametr
 *
 * \return wartość parametru obiektu
 */
  Object & Parametr() {  return parametr;  }

/*!
 * \brief Metoda przygotowująca obiekt do operacji
 *
 * \param[in] rozmiar - liczba elementów do przygotowania;
 *
 * \retval true - jeśli przygotowanie się powiodło
 * \retval false - jeśli wystąpił jakiś błąd
 */
  //virtual bool Prepare(int rozmiar) = 0;

  /*!
 * \brief Metoda przygotowująca obiekt do operacji z wykorzystaniem pliku
 *
 * \param[in] nazwaPliku - plik do pobrania danych
 * \param[in] rozmiar - liczba elementów do przygotowania;
 * \retval true - jeśli przygotowanie się powiodło
 * \retval false - jeśli wystąpił jakiś błąd
 */
  virtual bool PrepareUsingFile(string nazwaPliku, int rozmiar) = 0;

/*!
 * \brief Metoda uruchamiająca zdefiniowaną operację
 *
 * \param[in] track - parametr wykonania operacji
 * \retval true - jeśli operacja zakończyła się pomyślnie
 * \retval false - jeśli wystąpił jakiś błąd
 */
  virtual bool Run(Object track) = 0;
};

#endif
