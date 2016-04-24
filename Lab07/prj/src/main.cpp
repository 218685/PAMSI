#include <iostream>
#include "../inc/RBTree_Test.hh"
#include "../inc/AdvancedStopwatch.hh"
using namespace std;

int main()
{
  RBTree_Test<int>    T;
  AdvancedStopwatch   Stoper;
  
  int problemSize[6] = {10,100,1000,10000,100000,1000000};
  string nazwaPlikuOdczyt = "CzasOdczytu";
  
//różne wielkości problemów
  for(int j=0; j<6; ++j){
    cout << "N: " << setw(7) << problemSize[j] <<'\t';
  //seria pomiarow
    T.Prepare(problemSize[j]);
    for(int i=0; i<30; ++i){
    //pomiar odczytu elementu z drzewa 
      Stoper.Start();
      cout << T.Run() << " ";
      Stoper.Stop();
      Stoper.SaveElapsedTime(Stoper.GetElapsedTime());
    }
  //wyswietlenie sredniego czasu odczytu
    cout << endl << "Odczyt: "<<'\t';
    cout << fixed << setprecision(DOKLADNOSC) << Stoper.SeriesAverage() << " s" << endl;
    Stoper.SaveAverageTimeToBuffer(Stoper.SeriesAverage());
    Stoper.DumpToFile(nazwaPlikuOdczyt, Stoper.SeriesAverage());
    Stoper.CleanElapsedTimes();
    //T.PrintAll(T.Root());
  } // pierwszy for
  
  cout << endl;
  //cout << T.Root()->Element();
  return 0;
}

