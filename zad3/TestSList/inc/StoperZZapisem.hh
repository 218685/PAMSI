#ifndef STOPERZZAPISEM_HH
#define STOPERZZAPISEM_HH

#include "IStoper.hh"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define POJEMNOSC 35
#define BUFOR 6

/*!
 * \file StoperZZapisem.hh
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
class StoperZZapisem: public IStoper
{
  int rozm = 0;
  double * Notatnik;
  double * DoPliku;
public:
  StoperZZapisem();
  ~StoperZZapisem() { delete [] Notatnik; Notatnik = NULL; delete [] DoPliku; DoPliku = NULL; };
  int & Rozmiar(){ return rozm; };
  double* & Poczatek(){ return Notatnik; };
  double* & PoczatekBufora(){ return DoPliku; };
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
  void ShowMemory();

/*!
 * \brief Metoda usuwająca zawartość pamięci stopera
 */
  void CleanMemory();

/*!
 * \brief Metoda usuwająca zawartość bufora plikowego stopera
 */
  void CleanBuffer();

/*!
 * \brief Metoda wyliczająca średni czas okrążenia
 */
  double SeriesAverage();

/*!
 * \brief Metoda zapisująca zawartość bufora plikowego do pliku
 *
 * Dokonuje zapisu rekordów w buforze do pliku.
 * \param[in] plik - dowiązanie do pliku, do którego wykona zapis
 * \retval true - jeśli udało się zapisać
 * \retval false - jeśli udało się zapisać
 */
  bool DumpTimesToFile(ofstream & plik);

/*!
 * \brief Metoda zapisująca pojedynczy rekord bufora plikowego do pliku
 *
 * Dokonuje zapisu wybranego rekordu w buforze do pliku.
 * \param[in] plik - dowiązanie do pliku, do którego wykona zapis
 * \param[in] rekord - wartość pomiaru czasu, która ma być zapisana
 * \retval true - jeśli udało się zapisać
 * \retval false - jeśli udało się zapisać
 */
  bool DumpOneTimeToFile(ofstream & plik, double rekord);
};

#endif
