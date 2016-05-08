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
/*!
 * \brief Szablonowa klasa implementująca testowy graf
 */
template < typename Object >
class Graph_Test : public Graph, public IRunnable<Object>
{
  Object problemSize;
  char searchType = 'B'; 
public:
/*!
 * \brief Zmienia sposób przechodzenia grafu
 *
 * Ustawia podany typ znakowy jako wyznacznik przejścia grafu metodą BFS lub DFS.
 */
  void changeSearchType(char type);

/*!
 * \brief Metoda przygotowująca graf
 * W zależności od podanej liczby, dodaje odpowiednio dużo
 * wierzchołków do grafu i tworzy między nimi spójne powiązanie.
 * W następujący sposób:
 * tworzy tymczasową tablicę z numerami wierzchołków 
 * i następnie losowo zamienia komórki tablicy. Następnie dodaje
 * krawędzie zgodnie z wylosowaną kolejnością.
 * Na koniec generuje 2n losowych krawędzi.
 *
 * \param[in] parametr - liczba wierzchołków
 * \retval true - jeśli operacja zakończyła się pomyślnie
 * \retval false - jeśli wystąpił jakiś błąd
 */
  virtual bool Prepare(Object parametr);
  
/*!
 * \brief Metoda uruchamiająca przejście grafu
 * W zależności od ustawienia parametru searchType, uruchamia
 * przejście BFS lub DFS.
 * \retval true - jeśli operacja zakończyła się pomyślnie
 * \retval false - jeśli wystąpił jakiś błąd
 */
  virtual bool Run();
};

template < typename Object >
void Graph_Test<Object>::changeSearchType(char type){
  
  searchType = type;
}

template < typename Object >
bool Graph_Test<Object>::Prepare(Object parametr){
  
  problemSize = parametr;
  N = problemSize;
  if(Adj!=NULL)
    delete[] Adj;
  Adj = new BList<unsigned int>[N];
  //cout << maxN();
  srand(time(NULL));
//dodawanie wierzchołków
  for(int i=0; i<maxN(); ++i)
    insertVertex(i);

  unsigned* tmp = new unsigned int[maxN()];
  for(int i=0; i<maxN(); ++i)
    tmp[i] = i;

  for(int i=0; i<maxN()-1;++i)
    swap(tmp[i],tmp[rand()% maxN()]);
//generowanie spójnego grafu

  for(int i=0; i<maxN()-1; ++i) 
    insertEdge(tmp[i], tmp[i+1]);
  
  if(tmp!= NULL)
   delete [] tmp;
//losowanie dodatkowych krawędzi 
  unsigned beginning, end;
  
  for(int i=0; i<2*maxN(); ++i){
    beginning = rand() % maxN();
    end = rand() % maxN();
    insertEdge(beginning, end);
  }
 
  return true;
}

template < typename Object >
bool Graph_Test<Object>::Run(){

  if(searchType=='B')
    this->BFS(0);
  if(searchType=='D')
    this->DFS(0);
    
   return true;
}



#endif
