#ifndef GRAPH_HH
#define GRAPH_HH

#include <iostream>
#include "IGraph.hh"
#include "BList.hh"
#include "Vertex.hh"
#include "Edge.hh"
using namespace std;
/*!
 * \file Graph.hh
 *
 * Plik zawiera implementację interfejsu grafu.
 */
template < typename Object >
class Graph : public IGraph<Object>
{
  BList< Vertex<Object> > V;  /*!-> lista wierzchołków */
  BList< Edge<Object> > E;  /*!-> lista krawędzi */
  //unsigned** Adj;           /*!-> macierz sąsiedztwa */
  BList< BList<
public:
  Graph();
  Graph(unsigned problemSize);
  ~Graph();
  virtual unsigned* getNeighbours(unsigned i);
  virtual unsigned opposite(unsigned i);
  virtual bool areAdjacent(unsigned i, unsigned j); //czy są sąsiednie?
  
  virtual void insertVertex(unsigned i, const Object newValue);
  virtual void insertEdge(unsigned i, unsigned j, unsigned w = 1);
  virtual Object removeVertex(unsigned i); 
  virtual void removeEdge(unsigned i, unsigned j);
};

template < typename Object >
Graph(){
  
}

template < typename Object >
Graph(unsigned problemSize){
  
}

template < typename Object >
~Graph(){
  
}

template < typename Object >
unsigned* getNeighbours(unsigned i){
  
}

template < typename Object >
unsigned opposite(unsigned i){
  
}

template < typename Object >
bool areAdjacent(unsigned i, unsigned j){
  
}

template < typename Object >
void insertVertex(unsigned i, const Object newValue){
  
}

template < typename Object >
void insertEdge(unsigned i, unsigned j, unsigned w = 1){
  
}

template < typename Object >
Object removeVertex(unsigned i){
  
}

template < typename Object >
void removeEdge(unsigned i, unsigned j){}

#endif
