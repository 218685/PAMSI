#ifndef ADVANCEDSTOPWATCH_HH
#define ADVANCEDSTOPWATCH_HH

#include "Stopwatch.hh"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

#define MAX_LAPS 100
#define BUFOR 10

/*!
 * \file AdvancedStopwatch.hh
 *
 * Plik zawiera implementację rozbudowanego stopera.
 */

 /*!
 * \brief Klasa implementująca rozbudowany stoper
 *
 * Klasa jest modelelem stopera z funkcją zapisu czasu okrążeń,
 * liczeniem średniego czasu kilku okrążeń,
 * zapisu zmierzonych czasów do pliku.
 */
class AdvancedStopwatch: public Stopwatch
{
  unsigned rozm = 0;    /*!< liczba niezerowych elementów w tablicy czasów */
  double* ElapsedTimes; /*!< tablica czasów okrążeń w serii (do obliczania średniej) */
  double* FileBuffer;   /*!< bufor zapisu średnich czasów do pliku */
public:
  AdvancedStopwatch();
  ~AdvancedStopwatch();
  unsigned & Rozmiar(){ return rozm; };

/*!
 * \brief Metoda zapisująca wartość pomiaru czasu okrążenia
 *
 * Dodaje podany czas do tablicy czasów okrążeń.
 * \param[in] rekord - wartość pomiaru czasu
 * \retval true - jeśli udało się zapisać
 * \retval false - jeśli udało się zapisać
 */
  bool SaveElapsedTime(double rekord);

/*!
 * \brief Metoda wyliczająca średni czas okrążenia
 */
  double SeriesAverage();

/*!
 * \brief Metoda zapisująca średni czas okrążenia do bufora plikowego
 *
 * Dodaje podany czas do pamięci stopera,
 * z której można dokonać zapisu do pliku.
 * \param[in] rekord - wartość pomiaru czasu
 * \retval true - jeśli udało się zapisać
 * \retval false - jeśli udało się zapisać
 */
  bool SaveAverageTimeToBuffer(double rekord);

/*!
 * \brief Metoda wypisująca zawartość pamięci stopera
 */
  void PrintElapsedTimes();

/*!
 * \brief Metoda usuwająca zawartość pamięci stopera
 */
  void CleanElapsedTimes();

/*!
 * \brief Metoda usuwająca zawartość bufora plikowego stopera
 */
  void CleanFileBuffer();

/*!
 * \brief Metoda zapisująca zawartość bufora plikowego do pliku
 *
 * Dokonuje zapisu rekordów w buforze do pliku.
 * \param[in] nazwaPliku - nazwa pliku, do którego mają zostać zapisane czasy
 * \retval true - jeśli udało się zapisać
 * \retval false - jeśli udało się zapisać
 */
  bool DumpFileBuffer(string nazwaPliku);

/*!
 * \brief Metoda zapisująca pojedynczy rekord bufora plikowego do pliku
 *
 * Dokonuje zapisu wybranego rekordu w buforze do pliku.
 * \param[in] nazwaPliku - nazwa pliku, do którego ma zostać zapisany czas
 * \param[in] rekord - wartość pomiaru czasu, która ma być zapisana
 * \retval true - jeśli udało się zapisać
 * \retval false - jeśli udało się zapisać
 */
  bool DumpToFile(string nazwaPliku, double rekord);
};

#endif
