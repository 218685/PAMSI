#ifndef EMPTYUEEXCEPTION_HH
#define EMPTYQUEUEEXCEPTION_HH

#include <iostream>
using namespace std;

class EmptyQueueException
{
protected:
  string napis;
public:
  EmptyQueueException(string wyswietl){ cout << napis << endl;  }
};

#endif
