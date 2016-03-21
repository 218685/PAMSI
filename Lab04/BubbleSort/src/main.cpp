#include <iostream>
#include "Tab.hh"
using namespace std;

int main()
{
  Tab tablica;
  srand( time( NULL ) );
//losujemy liczby wpisane do tablicy
  for(int i=0; i<15; ++i)
    tablica.ZapiszNowy(rand() % 50 );

  cout << "Przed BubbleSort: " << endl;
  tablica.WypiszTab();

  tablica.BubbleSort();

  cout << "Po BubbleSort: " << endl;
  tablica.WypiszTab();

  return 0;
}
