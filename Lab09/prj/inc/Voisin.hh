#ifndef VOISIN_HH
#define VOISIN_HH

#include <iostream>
using namespace std;

class Voisin{
  unsigned i;
  int waga;
public:
  Voisin() { i = 0; waga = -1;}
  Voisin(unsigned neighbour, unsigned w = -1) { i = neighbour; waga = w;}
  unsigned& v() { return i;  }
  int& w() { return waga; }
};

  bool operator == (Voisin e1 , Voisin e2 ){
    if(e1.v() == e2.v())
      //if (e1.w() == e2.w())
        return true;
     
    return false;
  }
  
  bool operator != (Voisin e1 , Voisin e2 ){
    if(e1.v() != e2.v())
      return true;
      
    //if (e1.w() != e2.w())
      //return true;
    
    return false;
  }


ostream & operator << ( ostream & StrWy, Voisin & s){
  
  StrWy << s.v() <<"|"<< s.w();
  return StrWy;
}

ostream & operator << ( ostream & StrWy, Voisin* s ){
  
  StrWy << s->v() <<"|"<< s->w() ;
  return StrWy;
}


#endif
