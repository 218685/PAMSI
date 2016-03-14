#ifndef ISTACK_HH
#define ISTACK_HH

#include <iostream>
#include "EmptyStackException.hh"
using namespace std;

template < typename Object >
class IStack
{
public:
  bool IsEmpty();
  int Size();
  Object& Top() throw (EmptyStackException);
  void Push(Object item);
  Object& Pop() throw (EmptyStackException);
};

#endif
