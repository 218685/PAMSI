#ifndef ISTOPER_HH
#define ISTOPER_HH

#include <iostream>
#include <ctime>
using namespace std;

class IStoper
{
protected:
  clock_t start, koniec;
public:
  virtual void Start();
  virtual void Stop();
  virtual double GetElapsedTime();
  //virtual bool DumpElapsedTimeToCSV = 0;
};

#endif
