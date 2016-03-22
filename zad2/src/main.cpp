#include "IRunnable.hh"
#include "IStoper.hh"
#include "StoperZZapisem.hh"
#include "Tab.hh"
#include "TabTest.hh"
using namespace std;

int main()
{
  StoperZZapisem  Stoper;
  TabTest         Tabl;
  int ile[5] = {10,1000,100000,1000000,100000000};

  ofstream plik;
  plik.open("podwajanie_pojemnosci.txt" );

  Tabl.GetTyp() = 2;
//powiekszanie 2 razy
  for(int j=0; j<5; ++j){
  //seria pomiarow
    for(int i=0; i<POJEMNOSC; ++i){
      if( Tabl.Prepare(15) == true )
        Stoper.Start();
      if( Tabl.Run(ile[j]) == true )
        Stoper.Stop();
      Stoper.SaveElapsedTime(Stoper.GetElapsedTime());
      }
    //Stoper.ShowMemory();
    cout << Stoper.SeriesAverage() << " s" << endl;

    Stoper.SaveAverageTimeToBuffer(Stoper.SeriesAverage());
    if( plik.good() )
      Stoper.DumpOneTimeToFile(plik, Stoper.SeriesAverage());
    Stoper.CleanMemory();
    }

  plik.close();
  Stoper.CleanBuffer();

  ofstream plik1;
  plik1.open("dodawanie_po_1.txt" );
  cout << endl;

//powiekszanie po jednym
  Tabl.GetTyp() = 1;
  for(int j=0; j<5; ++j){
//seria pomiarow
    for(int i=0; i<POJEMNOSC; ++i){
      if( Tabl.Prepare(10) == true )
        Stoper.Start();
      if( Tabl.Run(ile[j]) == true )
        Stoper.Stop();
      Stoper.SaveElapsedTime(Stoper.GetElapsedTime());
      }
    //Stoper.ShowMemory();
    cout << Stoper.SeriesAverage() << " s" << endl;
    Stoper.SaveAverageTimeToBuffer(Stoper.SeriesAverage());
    if( plik1.good() )
      Stoper.DumpOneTimeToFile(plik1, Stoper.SeriesAverage());
    Stoper.CleanMemory();
    }
       plik1.close();
  return 0;
}

