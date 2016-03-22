#include "IStoper.hh"
using namespace std;

void IStoper::Start(){
  gettimeofday(&start, NULL);
  }

void IStoper::Stop(){
  gettimeofday(&stop, NULL);
  }

double IStoper::GetElapsedTime(){
  // zwracamy czas w sekundach
  double czas = stop.tv_sec + (stop.tv_usec/1000000.0) - start.tv_sec - (start.tv_usec/1000000.0);
  return czas;
  }

