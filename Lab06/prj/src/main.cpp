#include <iostream>
#include <iomanip>

#include "HashTab.hh"
#include "Stopwatch.hh"
#include "AdvancedStopwatch.hh"

using namespace std;

/*!
 * \file main.cpp
 * Zawiera kod źródłowy głównej funkcji programu.
 */

int main(int argc, char *argv[])
{
  HashTab<int>    tab;
  AdvancedStopwatch  Stoper;
  AdvancedStopwatch  StoperOdczyt;
  int losowanyKlucz;
  string keysTab[10] = {"Kenneth","Rahim","Underwood","TFfAvga","Ali","Dillon","NwFgq","Carter","Steven","Alec"};

  int nSize[6] = {10,100,1000,10000,100000,1000000};
//nazwy plików do pracy
  string nazwaPlikuInput = "RandomTextColumn";
  string nazwaPlikuZapis = "CzasZapisu";
  string nazwaPlikuOdczyt = "CzasOdczytu";
  string plikOdczyt = "Odczytane";
//uchwyty do plików do pracy
  fstream input;
  ofstream odczyt;
  odczyt.open(plikOdczyt.c_str());
//różne wielkości problemów
  for(int j=0; j<6; ++j){
  //seria pomiarow
    cout << "N: " << setw(7) << nSize[j] <<'\t';
    for(int i=0; i<25; ++i){
      tab.ResetBuckets(nSize[j]);
    //zapisywanie w tablicy
      input.open(nazwaPlikuInput.c_str());
      if( input.good() ){
        int newValue;
        string newKey;
        Stoper.Start();
        for(int k=0; k<nSize[j]; ++k){
          input >> newKey;
          input >> newValue;
          if( !input.eof() )
            tab[newKey.c_str()] = newValue;
          else
            break; //zakończ wczytywanie danych - wystąpił jakiś błąd (np. nie ma więcej danych w pliku)
          } //for
        }//if
      else
        cerr << "* Błąd pliku wejściowego." << endl;
      Stoper.Stop();
      Stoper.SaveElapsedTime(Stoper.GetElapsedTime());
      input.close();
  //pomiar czasu odczytu elementu o losowo wybranym kluczu
      losowanyKlucz = rand()%10;
      StoperOdczyt.Start();
      odczyt << "tab["<<keysTab[losowanyKlucz]<<"] = " << tab[keysTab[losowanyKlucz]]<<endl;
      StoperOdczyt.Stop();
      StoperOdczyt.SaveElapsedTime(StoperOdczyt.GetElapsedTime());
    }//środkowy for - serii 10 pomiarów
    odczyt << endl;
  //wyswietlenie sredniego czasu zapisu do tablicy
    cout << endl << "Zapis N: "<<'\t';
    cout << fixed << Stoper.SeriesAverage() << " s" << endl;
    Stoper.SaveAverageTimeToBuffer(Stoper.SeriesAverage());
    Stoper.DumpToFile(nazwaPlikuZapis, Stoper.SeriesAverage());
    Stoper.CleanElapsedTimes();
  //wyswietlenie sredniego czasu odczytu pojedynczego elementu
    cout << "Odczyt: "<<'\t';
    cout << fixed << StoperOdczyt.SeriesAverage() << " s" << endl;
    StoperOdczyt.SaveAverageTimeToBuffer(StoperOdczyt.SeriesAverage());
    StoperOdczyt.DumpToFile(nazwaPlikuOdczyt, StoperOdczyt.SeriesAverage());
    StoperOdczyt.CleanElapsedTimes();
    //tab.PrintAll();
  } // pierwszy for

  return 0;
}
