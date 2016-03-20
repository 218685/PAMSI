#include "IStoper.hh"
using namespace std;

void IStoper::Start(){
  start = clock();
  }

void IStoper::Stop(){
  koniec = clock();
  }

double IStoper::GetElapsedTime(){

  double czas = ((double) (koniec - start))/CLOCKS_PER_SEC;
  return czas;
  }

