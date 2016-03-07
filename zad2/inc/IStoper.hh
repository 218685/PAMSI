#ifndef ISTOPER_HH
#define ISTOPER_HH

#include <iostream>
#include <ctime>
using namespace std;

class IStoper
{
  clock_t start, koniec;
public:
  void Start() { start = clock();}
  void Stop()  { koniec = clock(); }
  double GetElapsedTime() { double czas = (double) (koniec - start)/ CLOCKS_PER_SEC; return czas; }
  bool DumpTimesToCSV = 0;
};
