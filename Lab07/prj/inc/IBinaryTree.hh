#ifndef IBINARYTREE_HH
#define IBINARYTREE_HH

#include <iostream>
using namespace std;

/*!
 * \file IBinaryTree.hh
 *
 * Plik zawiera interfejs drzewa binarnego.
 */
template < typename Object >
class IBinaryTree
{
public:
  virtual void Insert(const Object newItem) = 0;
  virtual void Remove(Object item) = 0;
  virtual bool IsEmpty() = 0;
};

#endif
