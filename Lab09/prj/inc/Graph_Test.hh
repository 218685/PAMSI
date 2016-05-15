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
  Object problemSize; /*!-> rozmiar problemu */
  char pathSearchType = 'S';  /*!-> metoda wyszukiwania ścieżki */
  unsigned pathEnd = 0;       /*!-> końcowy wierzchołek */
public:
/*!
 * \brief Zmienia sposób przechodzenia grafu
 *
 * Ustawia podany typ znakowy jako wyznacznik przejścia grafu metodą BFS lub DFS.
 */
  void changeSearchType(char type);
  
/*!
 * \brief Losuje końcowy wierzchołek 
 *
 * Losuje wierzchołek w zakresie od 0 do N, do którego ma zostać znaleziona najkrótsza ścieżka.
 */
  void RandomPathEnd();

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
  
  pathSearchType = type;
}

template < typename Object >
void Graph_Test<Object>::RandomPathEnd(){
  
  pathEnd = rand() % maxN();
}

template < typename Object >
bool Graph_Test<Object>::Prepare(Object parametr){
  
 // srand(time(NULL));
  problemSize = parametr;
  N = 0;
  N = problemSize;
 //czyszczenie 
  if(Adj != NULL)
    delete[] Adj;
    
  if(!V.IsEmpty())
    V.Clear();
    
  if(!E.IsEmpty())
    E.Clear(); 
  
  Adj = new BList<Voisin>[N+1];

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
    insertEdge(tmp[i], tmp[i+1], rand()%10+1);

  delete [] tmp;

//losowanie dodatkowych krawędzi 
  unsigned beginning, end;
  
  for(int i=0; i<2*maxN(); ++i){
    beginning = rand() % maxN();
    end = rand() % maxN();
    insertEdge(beginning, end, rand()%10+1);
  }
 
  return true;
}

template < typename Object >
bool Graph_Test<Object>::Run(){
 
  if(pathSearchType=='S')
    this->BranchBound(0, pathEnd);
  if(pathSearchType=='E')
    this->BranchBoundExtendedList(0, pathEnd);
    
   return true;
}



#endif
