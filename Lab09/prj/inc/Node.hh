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
 * \brief Klasa implementująca węzeł listy jednokierunkowej
 *
 * Węzeł pozwalana przechowywać dane w formie: (klucz, wartość).
 * Wartość może być dowolnego typu dzięki zastosowaniu
 * szablonu.
 */
template < typename Object >
class Node  // wezel dla listy w tablicy haszujacej
{
private:
  string key;           /*!< klucz */
  Object value = 0;       /*!< wartość */
  Node<Object>* next; /*!< wskaznik do nastepnego */
public:
/*!
 * \brief Metoda zwracająca obecny klucz węzła
 *
 * \return element w polu key węzła
 */
  string GetKey() { return key; }
/*!
 * \brief Metoda zwracająca obecną wartość węzła
 *
 * \return element w polu value węzła
 */
  Object & GetValue() { return value; }
/*!
 * \brief Metoda zwracająca wskaźnik do następnego węzła
 *
 * \return wskaźnik w polu next węzła
 */
  Node<Object>* GetNext() { return next; }
/*!
 * \brief Metoda przypisująca klucz do węzła
 *
 *  Ustawia podany element w polu key węzła.
 * \param[in] newKey - klucz do ustawienia w węźle
 */
  void SetKey(string newKey) { key = newKey; }
/*!
 * \brief Metoda przypisująca wartość do węzła
 *
 *  Ustawia podany element w polu value węzła.
 * \param[in] newValue - wartość do ustawienia w węźle
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
