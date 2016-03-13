#ifndef TABTEST_HH
#define TABTEST_HH

#include "Tab.hh"
#include "IRunnable.hh"
using namespace std;

class TabTest : public Tab, public IRunnable {
  int TypPowiekszania = 2;
public:
  int & GetTyp();
  virtual bool Prepare(int rozmiar);
  virtual bool Run(int track);
};

#endif
