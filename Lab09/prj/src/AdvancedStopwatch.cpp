#include "AdvancedStopwatch.hh"
using namespace std;

AdvancedStopwatch::AdvancedStopwatch(){

  ElapsedTimes = new double [MAX_LAPS];
  for(int i=0; i<MAX_LAPS; ++i)
     ElapsedTimes[i] = 0;

  FileBuffer = new double [BUFOR];
  for(int i=0; i<BUFOR; ++i)
     FileBuffer[i] = 0;
}

AdvancedStopwatch::~AdvancedStopwatch(){

  if(ElapsedTimes!=NULL)
    delete [] ElapsedTimes;
  ElapsedTimes = NULL;

  if(FileBuffer!=NULL)
    delete [] FileBuffer;
  FileBuffer = NULL;
}

bool AdvancedStopwatch::SaveElapsedTime(double rekord){

  for(int i=0; i<MAX_LAPS; ++i)
    if(ElapsedTimes[i] == 0){
      ElapsedTimes[i] = rekord;
      ++Rozmiar();
      return true;
      }
  return false;
}

double AdvancedStopwatch::SeriesAverage(){

  double average = 0;
  int sum = 0;
  for(int i=0; i<MAX_LAPS && ElapsedTimes[i] != 0; ++i){
      average += ElapsedTimes[i];
      sum++;
      }
  average = average/sum;
  return average;
}

bool AdvancedStopwatch::SaveAverageTimeToBuffer(double rekord){

  for(int i=0; i<BUFOR; ++i)
    if(FileBuffer[i] == 0){
      FileBuffer[i] = rekord;
      return true;
      }
  return false;
}
void AdvancedStopwatch::PrintElapsedTimes(){

  for(int i=0; i<MAX_LAPS && ElapsedTimes[i] != 0; ++i)
    cout << ElapsedTimes[i] <<'\t';

  cout << endl;
}

void AdvancedStopwatch::CleanElapsedTimes(){

  for(int i=0; i<MAX_LAPS && ElapsedTimes[i] != 0; ++i)
    ElapsedTimes[i] = 0;

  Rozmiar() = 0;
}

void AdvancedStopwatch::CleanFileBuffer(){

  for(int i=0; i<BUFOR; ++i)
    FileBuffer[i] = 0;
}

bool AdvancedStopwatch::DumpFileBuffer(string nazwaPliku){

  ofstream output;
  output.open(nazwaPliku.c_str(),ios::app);
  if( output.good() ){
    for (int i=0; i < BUFOR; ++i)
      if( FileBuffer[i] != 0 )
        output << fixed << setprecision(DOKLADNOSC) << FileBuffer[i] <<'\t'<< endl;
    output.close();
    return true;
    }
  else{
    cerr << "* Błąd: Nie można zapisać do pliku!" << endl;
    output.close();
    return false;
    }
}

bool AdvancedStopwatch::DumpToFile(string nazwaPliku, double rekord){

  ofstream output;
  output.open(nazwaPliku.c_str(),ios::app);
  if( output.good() ){
    output << fixed << setprecision(DOKLADNOSC) << rekord <<'\t'<< endl;
    output.close();
    return true;
    }
  else{
    cerr << "* Błąd: Nie można zapisać do pliku!" << endl;
    output.close();
    return false;
    }
}
