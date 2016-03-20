
#include "Stos.hh"

using namespace std;

/*
template <typename Object>
Stos<Object>::Stos(int ile){

  pojemnosc = ile;
  Tab = new Object[pojemnosc];
  top = -1; //działa jako indeks tablicy
  }

template <typename Object>
Stos<Object>::~Stos(){

  delete [] Tab;
  Tab = NULL;
}

template <typename Object>
bool Stos<Object>::IsEmpty(){

  if (top<0)
    return true;
  else
    return false;
}

template <typename Object>
int Stos<Object>::Size(){

  int rozm = top+1;
  return rozm;

}

template <typename Object>
Object& Stos<Object>::Top() throw (EmptyStackException){

  if(IsEmpty())
    throw EmptyStackException("Stos jest pusty.");
  return Tab[top];
}


template <typename Object>
void Stos<Object>::Push(Object item){

  if(Pojemnosc() > Size()){
    top++;
    Tab[top] = item;
    }
  else{
    Pojemnosc() = Pojemnosc()*2;    // podwajamy pojemnosc
    int *temp = new int [Pojemnosc()];  // tworzymy nowa tablice
    copy(Tab, Tab+(Pojemnosc()/2), temp);   //kopiujemy wszystkie elementy starej do nowej
    delete [] Tab;                // usuwamy stara tablice
    Tab = temp;
    Tab[top] = item;
  }

}

template <typename Object>
Object& Stos<Object>::Pop() throw (EmptyStackException){

  if(IsEmpty())
    throw EmptyStackException("Stos jest pusty.");
  return Tab[top--];
}
*/
