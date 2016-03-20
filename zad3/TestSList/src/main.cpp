#include <iostream>
#include <cstdlib>
#include <ctime>
#include "IRunnable.hh"
#include "IList.hh"
#include "SNode.hh"
#include "SLista.hh"
#include "TestSLista.hh"
#include "IStoper.hh"
#include "StoperZZapisem.hh"

using namespace std;
#define LOSOWANE 1000

/*!
 * \file main.cpp
 * Zawiera kod źródłowy głównego modułu programu.
 */

int main(int argc, char *argv[])
{
  StoperZZapisem      Stoper;
  TestSLista <string> listonic;
  string              NazwaPliku, DoLosowania;
  int                 ile[BUFOR] = {10,100,1000,1000000,10000000,100000000};

/**********/
//przygotowanie tablicy do losowania slowa do wyszukania na liscie
  srand( time( NULL ) ); //

  string excerpts[LOSOWANE];

  fstream excerpt;
  if(argc<3)
      DoLosowania = "Excerpts";
    else
      DoLosowania = argv[2];
  excerpt.open(DoLosowania);

  for(int i=0; i<LOSOWANE; ++i){
    string data;
    excerpt >> data;
    if( excerpt.good() )
      excerpts[i] = data;
    else
      break; //zakończ wczytywanie danych - wystąpił jakiś błąd (np. nie ma więcej danych w pliku)
    } //for
/***************/

  ofstream plik;
  plik.open("czas_przeszukiwania_listy.txt" );
/***************/
  for(int j=0; j<BUFOR; ++j){
  //seria pomiarow
   //listonic.printl();
    if(argc==1)
      NazwaPliku = "Tekst";
    else
      NazwaPliku = argv[1];
   if( listonic.PrepareUsingFile(NazwaPliku, ile[j]) ) // wypelnianie listy przed pomiarami czasu
    for(int i=0; i<POJEMNOSC; ++i){
    //wczytanie do listy odpowiedniej liczby slow
        Stoper.Start(); //zaczyna mierzyc czas
      if( listonic.Run(excerpts[(rand() % 1000 )])) //uruchomienie przeszukiwania listy dla losowego slowa
        Stoper.Stop();  //koniec pomiaru
      //cout << Stoper.GetElapsedTime() << endl;
      Stoper.SaveElapsedTime(Stoper.GetElapsedTime());  //zapis w pamieci do liczenia sredniej
      }

    //Stoper.ShowMemory();
    cout << Stoper.SeriesAverage() << " s" << endl;
    Stoper.SaveAverageTimeToBuffer(Stoper.SeriesAverage());
    if( plik.good() )
      Stoper.DumpOneTimeToFile(plik, Stoper.SeriesAverage());
    Stoper.CleanMemory();
    } // pierwszy for
/*************/
  plik.close();

  return 0;

}
