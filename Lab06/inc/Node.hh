#ifndef NODE_HH
#define NODE_HH

#include <iostream>
using namespace std;

/*!
 * \file Node.hh
 *
 *  Plik zawiera definicję węzła listy jednokierunkowej.
 */

/*!
 * \brief Klasa implementująca węzeł listy w tablicy z haszowaniem
 *
 *  Węzeł może przechowywać dowolny typ danych dzięki zastosowaniu
 *  szablonu.
 */
template < typename Object >
class Node  // wezel dla listy w tablicy haszujacej
{
private:
  string key;
  Object value;       // element wezla
  Node<Object>* next; // wskaznik do nastepnego
public:
/*!
 * \brief Metoda zwracająca obecny element węzła
 *
 * \return element w polu item węzła
 */
  string & Key() { return key; }
/*!
 * \brief Metoda zwracająca obecny element węzła
 *
 * \return element w polu item węzła
 */
  Object & Value() { return value; }

/*!
 * \brief Metoda zwracająca wskaźnik do następnego węzła
 *
 * \return wskaźnik w polu next węzła
 */
  Node<Object>* Next() { return next; }

/*!
 * \brief Metoda przypisująca element do węzła
 *
 *  Ustawia podany element w polu item węzła.
 * \param[in] newItem - element do ustawienia w węźle
 */
  void SetKey(string newKey) { key = newKey; }
/*!
 * \brief Metoda przypisująca element do węzła
 *
 *  Ustawia podany element w polu item węzła.
 * \param[in] newItem - element do ustawienia w węźle
 */
  void SetValue(Object newValue) { value = newValue; }

/*!
 * \brief Metoda przypisująca następny element do węzła
 *
 *  Ustawia podany wskaźnik w polu next węzła.
 * \param[in] newItem - wskaźnik do następnego węzła
 */
  void SetNext(Node<Object>* newItem)  { next = newItem; }
};


#endif
