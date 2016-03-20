#include <iostream>
/*
#include "IStack.hh"
#include "Stos.hh"
*/
#include "IQueue.hh"
#include "Kolejka.hh"
using namespace std;

int main()
{
  Kolejka <int> kju;

  kju.Enqueue(5);

  kju.Enqueue(6);

  kju.Enqueue(7);

  kju.Enqueue(8);

  kju.Enqueue(9);

  cout << "Liczba elementów w kolejce: " <<kju.Size()<<endl;
  try{
  cout<<"Element z przodu: "<< kju.Front() <<endl;
 cout<< "Usunieto: " << kju.Dequeue() << endl; //usunięcie 99
cout<< "Usunieto: " << kju.Dequeue() << endl; //usunięcie 43
  }
  catch(const char * napis) {
    cerr<<napis<<endl;
  }
  cout<<"Element z przodu: "<<kju.Front()<<endl;
  try{
  cout<< "Usunieto: " << kju.Dequeue() << endl; //usunięcie 23
  cout<< "Usunieto: " << kju.Dequeue() << endl; //usunięcie 12
  cout<< "Usunieto: " << kju.Dequeue() << endl;
  cout<< "Usunieto: " << kju.Dequeue() << endl;
  }
  catch(const char * napis) {
    cerr<<napis<<endl;
  }
  return 0;

}
