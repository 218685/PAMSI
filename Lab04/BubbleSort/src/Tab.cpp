#include "Tab.hh"
using namespace std;


int * Tab::WypelnijOdNowa(){

  delete []tab;
  tab = NULL;
  Rozmiar() = 0;
  Pojemnosc() = 10;

  int * tmp = new int [Pojemnosc()];
  for(int i = 0; i < Pojemnosc(); ++i){
    tmp[i]=i+1;
    ++Rozmiar();
    }

  return tmp;
}

int* Tab::Zwieksz2Razy()
{
  Pojemnosc()=Pojemnosc()*2;    // podwajamy pojemnosc
  int *temp = new int [Pojemnosc()];  // tworzymy nowa tablice
  copy(tab, tab+(Pojemnosc()/2), temp);   //kopiujemy wszystkie elementy starej do nowej
  delete [] tab;                // usuwamy stara tablice
  return temp;                  // zwracamy nowa powiekszona tablice
}

void Tab::ZapiszNowy(int elem){

  if(Rozmiar()==Pojemnosc())
    tab = Zwieksz2Razy();

  tab[Rozmiar()++] = elem;
}

void Tab::BubbleSort(){

  if(Rozmiar() <= 1)
    cerr << "Tablica jest zbyt mała!";
  else{
    for(int i = Rozmiar()-1; i>0 ; --i)  //iterator - zaczynamy od końca tablicy
      //jeśli i-ty element jest mniejszy niż poprzedni
      if(tab[i] < tab[i-1]){
        int tmp = tab[i];     // zapisujemy aktualny element
        tab[i] = tab[i-1];    // zamieniamy miejscami
        tab[i-1] = tmp;       // wpisujemy w nowe miejsce
        i = Rozmiar();
      }//if
    }//else
}

