#ifndef BNODE_HH
#define BNODE_HH

#include <iostream>
using namespace std;

template < typename Object >
class BNode  // wezel dla listy jednokierunkowej
{
private:
  Object item;      // element wezla
  BNode<Object>* next; // wskaznik do nastepnego
  BNode<Object>* previous; // wskaznik do nastepnego
  unsigned key;
public:
  BNode() { next = previous = NULL; key = 0; }
  Object& element() { return item; }
  unsigned& index() { return key; }
  BNode<Object>* next() { return next; }
  BNode<Object>* prev() { return previous; }
};


#endif
