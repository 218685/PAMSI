#ifndef ISTOPER_HH
#define ISTOPER_HH

#include <iostream>
#include <ctime>
using namespace std;

/*!
 * \file IStoper.hh
 *
 * Plik zawiera definicję interfejsu podstawowego stopera.
 */

 /*!
 * \brief Klasa modelująca interfejs stopera
 *
 * Klasa jest modelelem stopera o podstawowych funkcjach.
 *
 */
class IStoper
{
protected:
  clock_t start, koniec;
public:
/*!
 * \brief Metoda rozpoczynająca pomiar czasu
 */
  virtual void Start();

/*!
 * \brief Metoda kończąca pomiar czasu
 */
  virtual void Stop();

/*!
 * \brief Metoda podająca zmierzony czas
 *
 * \return zmierzony czas w sekundach
 */
  virtual double GetElapsedTime();
};

#endif
