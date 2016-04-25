#ifndef VERTEX_HH
#define VERTEX_HH

#include <iostream>
using namespace std;

template < typename Object >
class Vertex  // wezel drzewa binarnego
{
private:
  unsigned key;
  Object item;      // element wezla
  char color;
public:
  Vertex() { parent = left = right = NULL; key = 0; }
  ~Vertex() { parent = left = right = NULL; }
  Vertex(Object newItem) { item = newItem; key = 0;}
  Object & element() { return item; }
  unsigned & key() { return key; }
  char & color() {  return color; }

};


#endif
