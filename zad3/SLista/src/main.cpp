#include <iostream>
/*
#include "IStack.hh"
#include "Stos.hh"
*//*
#include "IQueue.hh"
#include "Kolejka.hh"*/
#include "IList.hh"
#include "SLista.hh"
#include "SNode.hh"
using namespace std;

int main()
{
  SLista <int> listonic;

  SNode<int>* znajdek = listonic.Find(3);

  if(znajdek==NULL)
    cout << "Nie znaleziono!" << endl;
  else
    cout << "Znaleziono" << endl;

  listonic.AddFront(3);
  listonic.AddFront(4);
  listonic.AddFront(5);
  listonic.AddFront(6);
  listonic.AddFront(7);
  try{
  cout<<"Element z przodu: "<< listonic.Front() <<endl;
  }
  catch(const char * napis) {
    cerr<<napis<<endl;
  }
  znajdek = listonic.Find(5);

  if(znajdek==NULL)
    cout << "Nie znaleziono!" << endl;
  else
    cout << "Znaleziono" << endl;

  listonic.AddFront(2);
  try{
  cout<<"Element z przodu: "<< listonic.Front() <<endl;

  cout<< "Usunieto: " << listonic.Front() << endl; //usunięcie 99
  listonic.RemoveFront();
    cout<< "Usunieto: " << listonic.Front() << endl; //usunięcie 43
      listonic.RemoveFront();
  }
  catch(const char * napis) {
    cerr<<napis<<endl;
  }
  cout<<"Element z przodu: "<<listonic.Front()<<endl;
  try{
  cout<< "Usunieto: " << listonic.Front()  << endl; //usunięcie 23
    listonic.RemoveFront();
  cout<< "Usunieto: " << listonic.Front() << endl; //usunięcie 12
    listonic.RemoveFront();
  cout<< "Usunieto: " << listonic.Front() << endl;
    listonic.RemoveFront();
  cout<< "Usunieto: " << listonic.Front() << endl;
    listonic.RemoveFront();
  }
  catch(const char * napis) {
    cerr<<napis<<endl;
  }
  return 0;

}
