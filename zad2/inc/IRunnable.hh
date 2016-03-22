#ifndef IRUNNABLE_HH
#define IRUNNABLE_HH

#include <iostream>
using namespace std;

class IRunnable
{
public:
  virtual bool Prepare(int rozmiar) = 0;
  virtual bool Run(int track) = 0;
};

#endif
