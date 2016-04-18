#ifndef IBINARYTREE_HH
#define IBINARYTREE_HH

#include <iostream>
#include "IBinaryTree.hh"
using namespace std;

template < typename Object >
class IBinaryTree:
{
public:
  virtual void Insert(const Object newItem) = 0;
  virtual Object& Remove(Object newItem) = 0;
  virtual bool IsEmpty() = 0;
  virtual Object Root() = 0;
};
