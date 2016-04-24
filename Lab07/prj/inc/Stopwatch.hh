#ifndef STOPWATCH_HH
#define STOPWATCH_HH

#include <iostream>
#include <ctime>
#include <sys/time.h>
using namespace std;

/*!
 * \file Stopwatch.hh
 *
 * Plik zawiera implementację podstawowego stopera.
 */

 /*!
 * \brief Klasa implementująca podstawowy stoper
 *
 * Klasa jest modelelem stopera z funkcjami start, stop i oblicz czas.
 */
class Stopwatch
{
protected:
  timeval start, stop; /*!< struktury timeval start i stop */
public:
/*!
 * \brief Rozpoczyna pomiar czasu
 *
 * Przypisuje wynik metody gettimeofday() do pola start.
 */
  virtual void Start();
/*!
 * \brief Kończy pomiar czasu
 *
 * Przypisuje wynik metody gettimeofday() do pola stop.
 */
  virtual void Stop();
/*!
 * \brief Oblicza czas na podstawie pól klasy
 *
 * Odejmuje wartości zapisane w polach stop i start.
 * Daje wynik w mikrosekundach.
 */
  virtual double GetElapsedTime();
};

#endif
