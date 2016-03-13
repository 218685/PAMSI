#ifndef IRUNNABLE_HH
#define IRUNNABLE_HH

#include <iostream>
using namespace std;

class IRunnable
{
protected:
  int wielkosc = 0;
public:
  int & Wielkosc();
  virtual bool Prepare(int rozmiar) = 0;
  virtual bool Run(int track) = 0;
};

#endif
