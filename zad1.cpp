#include <iostream>
using namespace std;

class Tab
{
  int n = 10;
  int * tab = new int [n];

public:
  int & Rozmiar(){   return n;  }
  int * & Wskaznik(){   return tab; }
  void WypelnijTab() {
  for( int i = 0; i < Rozmiar(); ++i)
        tab[i]=i+2;
  }
  void WypiszTab() {
  for ( int j = 0; j < Rozmiar(); ++j)
        cout<< tab[j] << '\t';
  }
  void ZmienWskaznik(int * Nowy);
  bool CzyPelna();
  bool ZapiszNowy(int elem);
  void PowiekszTablice(int ile);
};

bool Tab::CzyPelna(){
  if (tab[Rozmiar()] == NULL)
    return false;
  else
    return true;
}

void Tab::ZmienWskaznik(int * Nowy){
  int * temp;
  temp = Wskaznik();
  Wskaznik() = Nowy;
  delete [] temp;
}

void Tab::PowiekszTablice(int ile){
  int rozmiar = Rozmiar() + ile;
  int * kopia = new int [rozmiar];
  for( int i = 0; i < Rozmiar(); ++i)
        kopia[i]=tab[i];
  ZmienWskaznik(kopia);
  Rozmiar() = rozmiar;
}

bool Tab::ZapiszNowy(int elem){
  if( CzyPelna() == true)
  {/*
  int rozmiar = Rozmiar();
  int kopia[rozmiar];
  for( int i = 0; i < rozmiar; ++i)
    kopia[i]=tab[i];
  delete [] tab;
  tab = new int [++rozmiar];
  Wskaznik() = tab;
  for( int i = 0; i < rozmiar; ++i)
    {
    *Wskaznik()=kopia[i];
    Wskaznik()++;
    }

  *Wskaznik() = elem;
  Rozmiar() = rozmiar;
*/
  int rozmiar = Rozmiar();
  int kopia[rozmiar];
  for(int i = 0; i < rozmiar; ++i)
        kopia[i]=tab[i];
  delete [] tab;
  Rozmiar() = rozmiar + 1 ;
  int * tab = new int [Rozmiar()];

  for(int i = 0; i < Rozmiar(); ++i)
    tab[i] = kopia[i];

  tab[Rozmiar()] = elem;
  }
  else
    tab[Rozmiar()] = elem;

  return true;
}

int main()
{
Tab Tabl;
Tabl.WypelnijTab();
Tabl.WypiszTab();

 int ile;
/*
cout << endl << "Podaj element do tablicy: ";
cin >> x;
*/
cout << endl << "Podaj ile nowych elementów dodać: ";
cin >> ile;
for (int i=0; i < ile; i++)
  Tabl.ZapiszNowy(i);

  Tabl.WypiszTab();

return 0;

}
