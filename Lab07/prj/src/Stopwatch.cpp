#include "Stopwatch.hh"
using namespace std;

void Stopwatch::Start(){
  gettimeofday(&start, NULL);
  }

void Stopwatch::Stop(){
  gettimeofday(&stop, NULL);
  }

double Stopwatch::GetElapsedTime(){
  // zwracamy czas w usekundach
  double czas = stop.tv_sec + (stop.tv_usec/1000000.0) - start.tv_sec - (start.tv_usec/1000000.0);
  return czas;
  }

