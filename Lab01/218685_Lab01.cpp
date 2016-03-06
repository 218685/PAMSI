#include <iostream>
#include <ctime>
using namespace std;

class Tab
{
  int n=10;
  int rozm = 0;
  int * tab;

public:
  Tab() { tab = new int [n]; };
  ~Tab() { delete [] tab; tab = NULL; };
  int & Pojemnosc(){  return n;  };
  int & Rozmiar(){ return rozm; };
  int * & Poczatek(){ return tab; };
  void WypelnijTab() {  for( int i = 0; i < n; ++i){ tab[i]=i+1;  ++rozm; }}
  void WypiszTab() {  for ( int j = 0; j < rozm; ++j)  cout << tab[j] << '\t' << endl; }
  int * WypelnijOdNowa();
  void ZapiszNowy(int elem);
  void ZapiszNowyPoJednym(int elem);
  int* ZwiekszOJeden();
  int* Zwieksz2Razy();
};

int* Tab::ZwiekszOJeden(){

  ++Pojemnosc();    //zwiekszamy pojemnosc o 1
  int * nowa = new int [Pojemnosc()];   //nowa tablica wieksza o 1
  copy(tab, tab+Pojemnosc()-1, nowa);   // kopiojemy stara tablice do nowej
  delete [] tab;       // usuwamy stara tablice
  tab = NULL;
  return nowa;        // zwracamy nowa tablice
}

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

void Tab::ZapiszNowyPoJednym(int elem){

  if(Rozmiar()==Pojemnosc())
    tab = ZwiekszOJeden();

  tab[Rozmiar()++] = elem;
}

int main()
{
  clock_t start, koniec;
  Tab Tabl;
  Tabl.WypelnijTab();

  double czasy[5]={0,0,0,0,0};

  int ile[5] = {10,1000,100000,1000000,100000000};
cout << "Podwajanie pojemnosci tablicy: " << endl;
//powiekszanie 2 razy
  for(int j=0; j<5; ++j){
    start = clock();
    for (int i=0; i < ile[j]; i++)
      Tabl.ZapiszNowy(99);

    koniec = clock(); // bieżący czas systemowy w ms
    czasy[j] = (double) ( koniec - start) / CLOCKS_PER_SEC;
    cout << czasy[j] << " s" << endl;
    Tabl.Poczatek() = Tabl.WypelnijOdNowa();
    }

  cout << endl << "Dodawanie po jednym elemencie: " << endl;
//powiekszanie po jednym

  for(int j=0; j<5; ++j){
    start = clock();
    for (int i=0; i < ile[j]; i++){
      Tabl.ZapiszNowyPoJednym(99);
    }
    koniec = clock(); // bieżący czas systemowy w ms
    czasy[j] = (double) ( koniec - start) / CLOCKS_PER_SEC;
    cout << czasy[j] << " s" << endl;
    Tabl.Poczatek() = Tabl.WypelnijOdNowa();
    }


  return 0;
}
