#ifndef IQUEUE_HH
#define IQUEUE_HH

#include <iostream>
#include "EmptyQueueException.hh"
using namespace std;

template < typename Object >
class IQueue
{
public:
  bool IsEmpty();
  int Size();
  Object& Front() throw (EmptyQueueException);
  void Enqueue(Object item);
  Object& Dequeue() throw (EmptyQueueException);
};

#endif
