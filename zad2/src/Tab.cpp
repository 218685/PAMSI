#include "Tab.hh"
using namespace std;

int * Tab::ZwiekszOJeden(){

  ++Pojemnosc();    //zwiekszamy pojemnosc o 1
  int * nowa = new int [Pojemnosc()];   //nowa tablica wieksza o 1
  copy(tab, tab+Pojemnosc()-1, nowa);   // kopiujemy stara tablice do nowej
  delete [] tab;       // usuwamy stara tablice
  tab = NULL;
  return nowa;        // zwracamy nowa tablice
}

int * Tab::WypelnijOdNowa(){

  delete []tab;
  tab = NULL;
  Rozmiar() = 0;
  Pojemnosc() = 10;

  int * tmp = new int [Pojemnosc()];
  for(int i = 0; i < Pojemnosc(); ++i){
    tmp[i]=i+1;
    ++Rozmiar();
    }

  return tmp;
}

int* Tab::Zwieksz2Razy()
{
  Pojemnosc()=Pojemnosc()*2;    // podwajamy pojemnosc
  int *temp = new int [Pojemnosc()];  // tworzymy nowa tablice
  copy(tab, tab+(Pojemnosc()/2), temp);   //kopiujemy wszystkie elementy starej do nowej
  delete [] tab;                // usuwamy stara tablice
  return temp;                  // zwracamy nowa powiekszona tablice
}

void Tab::ZapiszNowy(int elem){

  if(Rozmiar()==Pojemnosc())
    tab = Zwieksz2Razy();

  tab[Rozmiar()++] = elem;
}

void Tab::ZapiszNowyPoJednym(int elem){

  if(Rozmiar()==Pojemnosc())
    tab = ZwiekszOJeden();

  tab[Rozmiar()++] = elem;
}
