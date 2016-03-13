#include "StoperZZapisem.hh"
using namespace std;

StoperZZapisem::StoperZZapisem(){

  Notatnik = new double [POJEMNOSC];
  for(int i=0; i<POJEMNOSC; ++i)
     Notatnik[i] = 0;

  DoPliku = new double [BUFOR];
  for(int i=0; i<BUFOR; ++i)
     DoPliku[i] = 0;
}

bool StoperZZapisem::SaveElapsedTime(double rekord){

  for(int i=0; i<POJEMNOSC; ++i)
    if(Notatnik[i] == 0){
      Notatnik[i] = rekord;
      ++Rozmiar();
      return true;
      }
  return false;
}

bool StoperZZapisem::SaveAverageTimeToBuffer(double rekord){

  for(int i=0; i<BUFOR; ++i)
    if(DoPliku[i] == 0){
      DoPliku[i] = rekord;
      return true;
      }
  return false;
}
void StoperZZapisem::ShowMemory(){

  for(int i=0; i<POJEMNOSC; ++i)
    cout << Notatnik[i] <<'\t';
  cout << endl;
}

void StoperZZapisem::CleanMemory(){

  for(int i=0; i<POJEMNOSC; ++i)
    Notatnik[i] = 0;
    Rozmiar() = 0;
}

void StoperZZapisem::CleanBuffer(){

  for(int i=0; i<BUFOR; ++i)
    DoPliku[i] = 0;
}

double StoperZZapisem::SeriesAverage(){

  double average = 0;
  int suma=0;
  for(int i=0; i<POJEMNOSC; ++i)
    if(Notatnik[i] != 0){
      average += Notatnik[i];
      suma++;
      }
  average = average/suma;
  return average;
}

bool StoperZZapisem::DumpTimesToFile(ofstream & plik){

  if( plik.good() ){
    for (int i=0; i < BUFOR; ++i)
      if( DoPliku[i] != 0 )
        plik << DoPliku[i] <<'\t'<< endl;
      plik << endl;
    return true;
    }
  else{
    cout << "* Błąd: Nie można zapisac do pliku!" << endl;
    return false;
    }
}

bool StoperZZapisem::DumpOneTimeToFile(ofstream & plik, double rekord){

  if( plik.good() ){
    plik << rekord <<'\t'<< endl;
    return true;
    }
  else{
    cout << "* Błąd: Nie można zapisac do pliku!" << endl;
    return false;
    }
}
