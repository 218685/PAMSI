#ifndef EDGE_HH
#define EDGE_HH

#include <iostream>
using namespace std;

template < typename Object >
class Edge  // krawędź grafu
{
private:
  unsigned start, end;
  Object weight;      
  unsigned key;
public:
  Edge() { weight = 1; )  
  Object & weight() { return  weight; }
  unsigned & start() { return start; }
  unsigned & end() { return end; }
  unsigned & key() { return key; }
};


#endif
