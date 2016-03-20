#include <iostream>
#include "IStack.hh"
#include "Stos.hh"
using namespace std;

int main()
{
  Stos <int> stosik(4);

  stosik.Push(5);
  stosik.Push(6);
  stosik.Push(7);
  stosik.Push(8);
  stosik.Push(9);


  cout<<"Liczba elementów na stosie: "<<stosik.Size()<<endl;
  try{
  cout<<"Element, który można usunąć: "<<stosik.Top()<<endl;
  stosik.Pop(); //usunięcie 99
  stosik.Pop(); //usunięcie 43
  }
  catch(const char * napis) {
    cerr<<napis<<endl;
  }
  cout<<"Element, który można usunąć: "<<stosik.Top()<<endl;
  try{
  stosik.Pop(); //usunięcie 23
  stosik.Pop(); //usunięcie 12
  stosik.Pop();
  }
  catch(const char * napis) {
    cerr<<napis<<endl;
  }
  return 0;

}
