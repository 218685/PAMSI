#ifndef EDGE_HH
#define EDGE_HH

#include <iostream>
using namespace std;

class Edge  // obiekt krawędzi grafu
{
private:
  unsigned i;    
  unsigned j;
  unsigned importance ;
public:
  Edge() { i = j = 0; importance = 1; }
  Edge(unsigned start, unsigned end, unsigned w = 1) { i = start; j = end; importance = w;}
  unsigned& w()   {return importance;}
  unsigned& beg() {return i;}
  unsigned& end() {return j;}
};

bool operator == (Edge e1 , Edge e2){
    if(e1.beg() == e2.beg())
      if (e1.end() == e2.end())
        //if (e1.w() == e2.w())
          return true;
    
    return false;
  }
  
  bool operator != (Edge e1 , Edge e2){
    if(e1.beg() != e2.beg())
      return true;
      
    if (e1.end() != e2.end())
      return true;
    
    //if (e1.w() != e2.w())
    //  return true;
    
    return false;
  }

#endif
