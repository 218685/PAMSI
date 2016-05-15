#ifndef GRAPH_HH
#define GRAPH_HH

#include <iostream>
#include "IGraph.hh"
#include "BList.hh"
#include "Edge.hh"
#include "Voisin.hh"
#include "Path.hh"
#include "Kolejka.hh"
#include "Stos.hh"
using namespace std;

/*!
 * \file Graph.hh
 *
 * Plik zawiera implementację interfejsu grafu.
 */
class Graph : public IGraph
{
protected:
  BList<unsigned> V;              /*!-> lista wierzchołków */
  BList<Voisin>* Adj;           /*!-> tablica list sąsiedztwa */
  BList<Edge> E;                /*!-> lista krawędzi */
  int N;
public:
 /*!
 * \brief Konstruktor grafu
 *
 * Inicjuje graf poprzez przypisanie tablicy list sąsiedztwa wskaźnika NULL.
 */
  Graph();
  
/*!
 * \brief Parametryczny konstruktor grafu
 *
 * Inicjuje graf poprzez utworzenie tablicy list sąsiedztwa 
 * dla podanej liczby wierzchołków.
 * \param[in] problemSize - liczba wierzchołków
 */
  Graph(int problemSize);
  
/*!
 * \brief Destruktor grafu
 *
 * Zwalnia pamięć zajmowaną przez tablicę list sąsiedztwa.
 * Wywołuje destruktor listy wierzchołków.
 */
  ~Graph();
  
/*!
 * \brief Podaje listę sąsiedztwa danego wierzchołka
 * \param[in] i - wierzchołek, którego lista sąsiedztwa ma być zwrócona
 * \return wskaźnik na lista sąsiedztwa podanego wierzchołka
 */
  BList<Voisin>* neighbours(unsigned i);
  
/*!
 * \brief Sprawdza, czy wierzchołki są sąsiadujące
 * Szuka wierzchołka j na liście sąsiedztwa wierzchołka i.
 * \param[in] i - wierzchołek pierwszy
 * \param[in] j - wierzchołek druga
 * \retval true - jeśli są sąsiednie
 * \retval false - jeśli nie są sąsiednie
 */
  virtual bool areAdjacent(unsigned i, unsigned j); //czy są sąsiednie?

/*!
 * \brief Dodaje wierzchołek
 * Dodaje do listy wierzchołków.
 * \param[in] i - numer wierzchołka
 */
  virtual void insertVertex(unsigned i);

/*!
 * \brief Dodaje krawędź
 * Dodaje wpisy na listach sąsiedztwa dla obu wierzchołków.
 * \param[in] i - numer wierzchołka pierwszego
 * \param[in] j - numer wierzchołka drugiego
 * \param[in] w - waga krawędzi
 */  
  virtual void insertEdge(unsigned i, unsigned j, unsigned w = 1);
 
  //virtual void removeVertex(unsigned i); 
  
  //virtual void removeEdge(unsigned i, unsigned j);

/*!
 * \brief Zwraca listę wierzchołków
 * 
 * \return lista sąsiedztwa podanego wierzchołka
 */
  BList<unsigned>& vertices() { return V; }
  
/*!
 * \brief Podaje maksymalną liczbę wierzchołków
 * \return rozmiar tablicy list sąsiedztwa
 */
  int& maxN() { return N; }

/*!
 * \brief Drukuje krawędzie grafu
 */
  void Print();
  
/*!
 * \brief Przechodzi graf wszerz
 * Wykorzystuje implementację kolejki.
 * \param[in] i - numer wierzchołka startowego
 */
  void BFS(unsigned i);
  
/*!
 * \brief Przechodzi graf wgłąb
 * Wykorzystuje implementację stosu.
 * \param[in] i - numer wierzchołka startowego
 */
  void DFS(unsigned i);
  
/*!
 * \brief Wyszukuje najkrótszą ścieżkę w grafie metodą Branch&Bound
 * 
 * \param[in] i - numer wierzchołka startowego
 * \param[in] finish - numer wierzchołka końcowego
 */
  void BranchBound(unsigned i,unsigned finish);

/*!
 * \brief Wyszukuje najkrótszą ścieżkę w grafie metodą Branch&Bound with Extended List
 * 
 * \param[in] i - numer wierzchołka startowego
 * \param[in] finish - numer wierzchołka końcowego
 */
  void BranchBoundExtendedList(unsigned i, unsigned finish);
};

Graph::Graph(){
  
  N = 0;
  Adj = NULL;
  V.Head() = NULL;
  V.Tail() = NULL;
  E.Head() = NULL;
  E.Tail() = NULL;
}

Graph::Graph(int problemSize){
  
  N = problemSize;
  Adj = new BList<Voisin>[N+1];
}

Graph::~Graph(){
  
  if(Adj!=NULL){
    delete [] Adj;
  
  Adj = NULL;
  }
}

BList<Voisin>* Graph::neighbours(unsigned i){
  
  if(!Adj[i].IsEmpty())
    return &Adj[i];
  else
    return NULL;
}

bool Graph::areAdjacent(unsigned i, unsigned j){

  Voisin s(j);
  //sprawdź, czy jest na niej podany wierzchołek
  if(Adj[i].Find(s)!=NULL)
    return true;
  
  return false;
}

void Graph::insertVertex(unsigned i){
  
 //dodanie nowego wierzchołka do listy
  V.AddFront(i);
}

void Graph::insertEdge(unsigned i, unsigned j, unsigned w){

//zakładamy, że nie ma krawędzi powracających
  if(i!=j){
  //sprawdzamy, czy jest już krawędź o podanej wadze pomiędzy wierzchołkami
    if(!areAdjacent(i,j)){
    //dodanie sąsiada na liście sąsiedztwa
      Voisin a(i,w), b(j,w);
      Adj[i].AddFront(b);
      Adj[j].AddFront(a);
    //dodanie krawędzi
      Edge e(i,j,w);
      E.AddFront(e);
    }
  }
}

void Graph::Print(){
 
  if(Adj!=NULL)
  for(int i = 0; i<N; ++i)
    if(!Adj[i].IsEmpty()){
      cout << i << " <-->";
      Adj[i].Print();
    }
  
}

void Graph::DFS(unsigned i){
  
  bool* visited = new bool[maxN()];
  for(int i=0; i<maxN(); ++i)
    visited[i] = false;
    
  Stos<unsigned> S(maxN());
  
  S.Push(i);
  visited[i] = true;     // Oznaczamy wierzchołek startotwy jako odwiedzony

  BNode<Voisin>* p;
  
  while( !S.IsEmpty() ){
  // Odczytujemy wierzchołek ze stosu
    i = S.Top();
    //cout << i << " "; 
  // Wierzchołek usuwamy ze stosu
    S.Pop();
    // Przeglądamy jego listę sąsiedztwa
    if(!neighbours(i)->IsEmpty()){
      for( p = neighbours(i)->Head(); p!=NULL; p = p->next() ){
        //jeśli nie jest odwiedzony, dodajemy na stos
        if(visited[p->element().v()]!=true){
        unsigned v = p->element().v();
        S.Push(v);
        visited[v] = true; // i oznaczamy jako odwiedzony
        }
      }//for
    }
  }
  
  delete[] visited;
}

void Graph::BFS(unsigned i){
  
  bool* visited = new bool[maxN()];
  for(int i=0; i<maxN(); ++i)
    visited[i] = false;
  BNode<Voisin>* p;
  //nowa kolejka
  Kolejka<unsigned> Q;
  // W kolejce umieszczamy węzeł startowy
  Q.Enqueue(i);
  visited[i] = true;      // Wierzchołek i oznaczamy jako odwiedzony
  
  while( !Q.IsEmpty() ){
   //Odczytujemy węzeł z kolejki
    i = Q.Front();          
    //cout << i << " ";
    Q.Dequeue();
    if(!neighbours(i)->IsEmpty()){
      for( p = neighbours(i)->Head(); p!=NULL; p = p->next() ){
        if(visited[p->element().v()]!=true){
          unsigned v = p->element().v();
          Q.Enqueue(v);
          visited[v] = true; // i oznaczamy ich jako odwiedzonych
        }
      }//for
    }
  }
  
  delete[] visited;
}

void Graph::BranchBound(unsigned i, unsigned finish){
/*
  create a list P
  add the start node S, to P giving it one element
  Until first path of P ends with G, or P is empty
      extract the first path from P
      extend first path one step to all neighbors creating X new paths
      reject all paths with loops
      add each remaining new path to of P
      Sort all paths by current distance travelled, shortest first.
  If G found -> success. Else -> failure.	*/
    
  BNode<Voisin>* p;
  Voisin u;
  
  //lista ścieżek
  BList<Path> L;
  Path S;
  S.c() = 0;
  S.V().push_back(i);
  L.AddFront(S);
 // L.Print();
  Path currentPath,  currentBest;
  vector<Path> tmp;
  int licznikSciezek = 0;
  while( !L.IsEmpty() ){
   //Odczytujemy węzeł z kolejki
    currentPath = L.RemoveFront();  
   // cout << " LISTA: " << currentPath << endl;
    unsigned currentTop = currentPath.V().back();
    if(currentTop == finish){
      cout << "   Najkrótsza ścieżka: " << currentPath << endl;
      break;
    }
 //dla każdego wierzchołka na liście sąsiedztwa wierzchołka i
    for( p = neighbours(currentTop)->Head(); p!=NULL; p = p->next() ){
      u = p->element();
    //sprawdzamy, czy ścieżka nie jest zapętlona
      
      if( !currentPath.Find( u.v() )){
     //wydłużamy ścieżkę o jeden krok
        Path extendedPath;
        extendedPath = currentPath;
        //dodajemy kolejny wierzchołek
        extendedPath.V().push_back(u.v());
        extendedPath.c() += u.w();
        //dodajemy do pomocniczej struktury
        tmp.push_back(extendedPath);
        ++licznikSciezek;
      }
    }//for  
 /*
    for (vector<Path>::iterator it = tmp.begin() ; it != tmp.end(); ++it)
      cout << *it << endl;*/
      //po dodaniu wszystkich nowych ścieżek 
      //dokonujemy "sortowania", żeby ścieżka o najkrótszej 
      //drodze była zawsze na początku listy

  Path currentBest;
  int bestCost = 100000000;
  vector<Path>::iterator it, toErase;
 
  for (it = tmp.begin(); it != tmp.end(); ++it)
    if( (*it).c() < bestCost){
      bestCost = (*it).c();
     // cout << "Bestcost: " << bestCost << endl;
      currentBest = *it;
      toErase = it;
    } 
  L.AddFront(currentBest);
  
  tmp.erase(toErase);
  //cin >> sa;
  //tmp.clear();
  }//while
  cout << "   Sprawdzono ścieżek: " << licznikSciezek << endl;
  tmp.clear();
}


void Graph::BranchBoundExtendedList(unsigned i, unsigned finish){
  
  //tablica wierzchołków rozszerzonych
  bool* extended = new bool[maxN()];
  for(int i=0; i<maxN(); ++i)
    extended[i] = false;
  
  BNode<Voisin>* p;
  Voisin u;
  
  //lista ścieżek
  BList<Path> L;
  Path S;
  S.c() = 0;
  S.V().push_back(i);
  L.AddFront(S);

  Path currentPath,  currentBest;
  vector<Path> tmp;
  int licznikSciezek = 0;
  while( !L.IsEmpty() ){
   //Odczytujemy węzeł z kolejki
    currentPath = L.RemoveFront();  
   // cout << " LISTA: " << currentPath << endl;
    unsigned currentTop = currentPath.V().back();
    if(currentTop == finish){
      cout << "   Najkrótsza ścieżka: " << currentPath << endl;
      break;
    }
  //jeśi wcześniej nie rozwinięto tego wierzchołka
    if( extended[currentTop]!=true ){
  //dla każdego wierzchołka na liście sąsiedztwa wierzchołka i
      for( p = neighbours(currentTop)->Head(); p!=NULL; p = p->next() ){
        u = p->element();
      //sprawdzamy, czy ścieżka nie jest zapętlona
        
        if( !currentPath.Find( u.v() )){
      //wydłużamy ścieżkę o jeden krok
          Path extendedPath;
          extendedPath = currentPath;
          //dodajemy kolejny wierzchołek
          extendedPath.V().push_back(u.v());
          extendedPath.c() += u.w();
          //dodajemy do pomocniczej struktury
          tmp.push_back(extendedPath);
          ++licznikSciezek;
        }
      }//for 
      extended[currentTop] = true;
    } 
    
 /*   for (vector<Path>::iterator it = tmp.begin() ; it != tmp.end(); ++it)
      cout << *it << endl;*/
      //po dodaniu wszystkich nowych ścieżek 
      //dokonujemy "sortowania", żeby ścieżka o najkrótszej 
      //drodze była zawsze na początku listy

  Path currentBest;
  int bestCost = 100000000;
  vector<Path>::iterator it, toErase;
 
  for (it = tmp.begin(); it != tmp.end(); ++it)
    if( (*it).c() < bestCost){
      bestCost = (*it).c();
     // cout << "Bestcost: " << bestCost << endl;
      currentBest = *it;
      toErase = it;
    } 
  L.AddFront(currentBest);
  
  tmp.erase(toErase);
  }//while
  cout << "   Sprawdzono ścieżek: " << licznikSciezek << endl;
  tmp.clear();
  delete[] extended;
}

#endif
