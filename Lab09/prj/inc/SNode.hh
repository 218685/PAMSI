#ifndef SNODE_HH
#define SNODE_HH

#include <iostream>
using namespace std;

template < typename Object >
class SNode  // wezel dla listy jednokierunkowej
{
private:
  Object item;      // element wezla
  SNode<Object>* next; // wskaznik do nastepnego
public:
  SNode(){ next = NULL; }
  Object GetElement() { return item; }
  SNode<Object>* GetNext() { return next; }
  void SetElement(Object newItem) { item = newItem; }
  void SetNext(SNode<Object>* newItem)  { next = newItem; }
};


#endif
