#ifndef IGRAPH_HH
#define IGRAPH_HH

#include <iostream>
using namespace std;

/*!
 * \file IGraph.hh
 *
 * Plik zawiera interfejs grafu.
 */
//template < typename Object >
class IGraph
{
public:
  //virtual unsigned* getNeighbours(unsigned i) = 0;
  virtual bool areAdjacent(unsigned i, unsigned j) = 0; //czy są sąsiednie?
  
  virtual void insertVertex(unsigned i) = 0;//,const Object newValue) = 0;
  virtual void insertEdge(unsigned i, unsigned j, unsigned w = 1) = 0;
  //virtual void removeVertex(unsigned i) = 0; 
  //virtual void removeEdge(unsigned i, unsigned j) = 0;
};

#endif
