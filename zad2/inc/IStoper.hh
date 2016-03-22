#ifndef ISTOPER_HH
#define ISTOPER_HH

#include <iostream>
#include <ctime>
#include <sys/time.h>
using namespace std;

class IStoper
{
protected:
  timeval start,stop;
public:
  virtual void Start();
  virtual void Stop();
  virtual double GetElapsedTime();
  //virtual bool DumpElapsedTimeToCSV = 0;
};

#endif
