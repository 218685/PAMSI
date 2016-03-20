#ifndef SNODE_HH
#define SNODE_HH

#include <iostream>
using namespace std;

/*!
 * \file  SNode.hh
 *
 *  Plik zawiera definicję węzła listy jednokierunkowej.
 */

/*!
 * \brief Klasa implementująca węzeł listę jednokierunkową
 *
 *  Węzeł może przechowywać dowolny typ danych dzięki zastosowaniu
 *  szablonu.
 */
template < typename Object >
class SNode  // wezel dla listy jednokierunkowej
{
private:
  Object item;      // element wezla
  SNode<Object>* next; // wskaznik do nastepnego
public:
/*!
 * \brief Metoda zwracająca obecny element węzła
 *
 * \return element w polu item węzła
 */
  Object GetElement() { return item; }

/*!
 * \brief Metoda zwracająca wskaźnik do następnego węzła
 *
 * \return wskaźnik w polu next węzła
 */
  SNode<Object>* GetNext() { return next; }

/*!
 * \brief Metoda przypisująca element do węzła
 *
 *  Ustawia podany element w polu item węzła.
 * \param[in] newItem - element do ustawienia w węźle
 */
  void SetElement(Object newItem) { item = newItem; }

/*!
 * \brief Metoda przypisująca następny element do węzła
 *
 *  Ustawia podany wskaźnik w polu next węzła.
 * \param[in] newItem - wskaźnik do następnego węzła
 */
  void SetNext(SNode<Object>* newItem)  { next = newItem; }
};


#endif
