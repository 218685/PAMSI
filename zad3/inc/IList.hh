#ifndef ILIST_HH
#define ILIST_HH

#include <iostream>
#include "EmptyListException.hh"
using namespace std;

template < typename Type >
class IList
{
public:
  bool IsEmpty();
  int Size();
  void Add(Type item, int index);
  Type& Remove(int index) throw(EmptyListException);
  Type& GetItem(int index) throw(EmptyListException);
};

#endif
