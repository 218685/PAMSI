#ifndef IASSOCIATIVE_HH
#define IASSOCIATIVE_HH

#include <iostream>
using namespace std;

/*!
 * \file IAssociative.hh
 *
 *  Plik zawiera interfejs tablicy asocjacyjnej.
 */

/*!
 * \brief Szablonowa klasa interfejsu tablicy asocjacyjnej.
 *
 * Definiuje ADT dla tablicy asocjacyjnej.
 */
template < typename Object >
class IAssociative
{
public:
/*!
 * \brief Przeciążenie operatora indeksującego tablicy asocjacyjnej
 *
 * Umożliwia odczyt i zapis do tablicy z haszowaniem elementu o podanym kluczu.
 *
 * \param[in] klucz - łańcuch znakowy do dodania lub odczytania
 * \return Wartość pod wskazanym kluczem.
 */
  virtual Object & operator[](string klucz) = 0;

/*!
 * \brief Dodaje wartość o podanym kluczu
 *
 * \param[in] klucz - łańcuch znakowy do dodania
 * \param[in] newItem - wartość dostępna pod podanym kluczem
 * \return Indeks w tablicy, pod którym znajdzie się podany klucz.
 */
  virtual unsigned Insert(string klucz, Object newItem) = 0;

/*!
 * \brief Szuka wartości o podanym kluczu
 *
 * Zwraca wartość dostępną pod podanym kluczem.
 *
 * \param[in] klucz - łańcuch znakowy do wyszukania
 * \return Wartość pod wskazanym kluczem.
 */
  virtual Object Search(string klucz) = 0;

/*!
 * \brief Usuwa element o podanym kluczu
 *
 * Usuwa element z tablicy. Zwraca wartość pod podanym kluczem.
 *
 * \param[in] klucz - łańcuch znakowy do wyszukania
 * \return Wartość pod wskazanym kluczem.
 */
  virtual Object Delete(string klucz) = 0;
};

#endif
