#ifndef GRAPH_TEST_HH
#define GRAPH_TEST_HH

#include <iostream>
#include "IRunnable.hh"
#include "Graph.hh"
using namespace std;
/*!
 * \file Graph_Test.hh
 *
 * Plik zawiera implementację IRunnable dla grafu (operacje BFS i DFS).
 */
template < typename Object >
class Graph_Test : public Graph<Object>, public IRunnable<Object>
{
  unsigned problemSize;
public:
  virtual bool Prepare(Object parametr);
  virtual bool Run();
};

#endif
