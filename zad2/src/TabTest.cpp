#include "TabTest.hh"
using namespace std;

int & TabTest::GetTyp(){

  return TypPowiekszania;
  }

bool TabTest::Prepare(int rozmiar){

  if(Rozmiar()!=0){
    delete [] tab;
    Rozmiar() = 0;
    Pojemnosc() = rozmiar;

    int * tmp = new int [Pojemnosc()];
    for(int i = 0; i < Pojemnosc(); ++i){
      tmp[i]=i+1;
      ++Rozmiar();
      }
    tab = tmp;
    }
  else{
    WypelnijTab();
    Wielkosc() = rozmiar;
    }

  return true;
}

bool TabTest::Run(int track){
  if( GetTyp()==2 )
    for (int i=0; i < track; i++)
      ZapiszNowy(99);
  if( GetTyp()==1 )
     for (int i=0; i < track; i++)
      ZapiszNowyPoJednym(99);
  return true;
}
