#ifndef PATH_HH
#define PATH_HH

#include <iostream>
#include <vector>
#include "BList.hh"
using namespace std;

class Path 
{
  vector<unsigned> vertices;  /*!-> lista wierzchołków */
  int cost = 0 ;  /*!-> długość ścieżki */
  public:
    vector<unsigned>& V() {return vertices;}
    int& c() {return cost;}
    /*!
 * \brief Szuka wierzchołka j w ścieżce 
 * \param[in] k - wierzchołek do wyszukania

 * \retval true - jeśli znalezniono
 * \retval false - jeśli nie znalezniono
 */
    bool Find(unsigned k);
};

bool Path::Find(unsigned k){
  
  for (vector<unsigned>::iterator it = V().begin() ; it != V().end(); ++it)
    if( *it==k)
      return true;
      
  return false;
}

ostream & operator << ( ostream & StrWy, Path s){
  
  for (vector<unsigned>::iterator it = s.V().begin() ; it != s.V().end(); ++it)
    StrWy << "->" << *it;
  StrWy << " | $"<< s.c();
  return StrWy;
}

ostream & operator << ( ostream & StrWy, Path * s){
  
  for (vector<unsigned>::iterator it = s->V().begin() ; it != s->V().end(); ++it)
    StrWy << *it << "->";
  StrWy << " | "<< s->c();
  return StrWy;
}
#endif
