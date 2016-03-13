#ifndef STOPERZZAPISEM_HH
#define STOPERZZAPISEM_HH

#include "IStoper.hh"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define POJEMNOSC 10
#define BUFOR 5

class StoperZZapisem: public IStoper
{
  int rozm = 0;
  double * Notatnik;
  double * DoPliku;
public:
  StoperZZapisem();
  ~StoperZZapisem() { delete [] Notatnik; Notatnik = NULL; delete [] DoPliku; DoPliku = NULL; };
  int & Rozmiar(){ return rozm; };
  double* & Poczatek(){ return Notatnik; };
  double* & PoczatekBufora(){ return DoPliku; };
  bool SaveElapsedTime(double rekord);
  bool SaveAverageTimeToBuffer(double rekord);
  void ShowMemory();
  void CleanMemory();
  void CleanBuffer();
  double SeriesAverage();
  bool DumpTimesToFile(ofstream & plik);
  bool DumpOneTimeToFile(ofstream & plik, double rekord);
};

#endif
