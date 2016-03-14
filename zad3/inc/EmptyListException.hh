#ifndef EMPTYLISTEXCEPTION_HH
#define EMPTYLISTEXCEPTION_HH

#include <iostream>
using namespace std;

class EmptyListException
{
protected:
  string napis;
public:
  EmptyListException(string wyswietl){ cout << wyswietl << endl;  }
};

#endif
