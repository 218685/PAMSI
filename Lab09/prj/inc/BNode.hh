#ifndef BNODE_HH
#define BNODE_HH

#include <iostream>
using namespace std;

template < typename Object >
class BNode  // wezel dla listy jednokierunkowej
{
private:
  Object item;      // element wezla
  BNode<Object>* nextn; // wskaznik do nastepnego
  BNode<Object>* previous; // wskaznik do nastepnego
  unsigned key;
public:
  BNode() { nextn = previous = NULL; key = 0; }
  Object& element() { return item; }
  unsigned& index() { return key; }
  BNode<Object>* & next() { return nextn; }
  BNode<Object>* & prev() { return previous; }
};


#endif
