#include "IRunnable.hh"
#include "IStoper.hh"
#include "Tab.hh"
#include <iostream>
using namespace std;

int main()
{
  IStoper Stoper;
  Tab Tabl;

  double czasy[5]={0,0,0,0,0};

  int ile[5] = {10,1000,100000,1000000,100000000};

//powiekszanie 2 razy
  for(int j=0; j<5; ++j){
    if(Tabl.Prepare()==true)
      Stoper.Start();
    if(Tabl.Run()==true)
      Stoper.Stop();
    czasy[j] = Stoper.GetElapsedTime();
    cout << czasy[j] << " s" << endl;
    }

  cout << endl;
//powiekszanie po jednym
/*
  for(int j=0; j<5; ++j){
    start = clock();
    for (int i=0; i < ile[j]; i++){
      Tabl.ZapiszNowyPoJednym(99);
    }
    koniec = clock(); // bieżący czas systemowy w ms
    czasy[j] = (double) ( koniec - start) / CLOCKS_PER_SEC;
    cout << czasy[j] << " s" << endl;
    Tabl.Poczatek() = Tabl.WypelnijOdNowa();
    }
*/

  return 0;
}
