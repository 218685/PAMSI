#ifndef TAB_HH
#define TAB_HH

#include <iostream>
using namespace std;

class Tab
{
protected:
  int n = 1;
  int rozm = 0;
  int * tab;
public:
  Tab() { tab = new int [n]; };
  Tab(int ile) { if(ile!=0)
                  tab = new int [ile];
                else
                  tab = new int [n];};
  ~Tab() { delete [] tab; tab = NULL; };
  int & Pojemnosc(){  return n;  };
  int & Rozmiar(){ return rozm; };
  int* & Poczatek(){ return tab; };
  void WypelnijTab() {  for( int i = 0; i < n; ++i){ tab[i]=i+1;  ++rozm; }}
  void WypiszTab() {  for ( int j = 0; j < rozm; ++j)  cout << tab[j] << endl; }
  int* WypelnijOdNowa();
  void ZapiszNowy(int elem);
  int* Zwieksz2Razy();
  void BubbleSort();
};

#endif
