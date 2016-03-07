#ifndef IRUNNABLE_HH
#define IRUNNABLE_HH

#include <iostream>
using namespace std;

class IRunnable
{
protected:
  int wielkosc = 0;
public:
  int & Wielkosc() { return wielkosc; }
  virtual bool Prepare(int rozmiar) = 0;
  virtual bool Run() = 0;
};
