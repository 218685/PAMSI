#ifndef EMPTYSTACKEXCEPTION_HH
#define EMPTYSTACKEXCEPTION_HH

#include <iostream>
using namespace std;

class EmptyStackException
{
protected:
  string napis;
public:
  EmptyStackException(string wyswietl){ cout << wyswietl << endl;  }
};

#endif
