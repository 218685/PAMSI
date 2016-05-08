#include <iostream>
//#include "Graph.hh"
#include "Graph_Test.hh"
#include "AdvancedStopwatch.hh"
using namespace std;

int main()
{
  
  Graph_Test<int> G;
  
  AdvancedStopwatch  StoperBFS;
  AdvancedStopwatch  StoperDFS;
 
  int nSize[7] = {10,100,1000,10000,100000,1000000,10000000};
//nazwy plików do pracy
  string nazwaPlikuBFS = "CzasBFS";
  string nazwaPlikuDFS = "CzasDFS";
//różne wielkości problemów
  for(int j=6; j<7; ++j){
  //przygotowanie grafu
    cout << "N: " << setw(7) << nSize[j] <<'\t';
    G.Prepare(nSize[j]);
    for(int i=0; i<15; ++i){
      //G.Prepare(nSize[j]);
      StoperBFS.Start();
      G.Run();
      StoperBFS.Stop();
      StoperBFS.SaveElapsedTime(StoperBFS.GetElapsedTime());
   //przeszukiwanie DFS
      G.changeSearchType('D');
      StoperDFS.Start();
      G.Run();
      StoperDFS.Stop();
      StoperDFS.SaveElapsedTime(StoperDFS.GetElapsedTime());
    }//środkowy for - seria 10 pomiarów
  //wyswietlenie średnich czasów
    cout << endl << "BFS N: "<<'\t';
    cout << fixed << StoperBFS.SeriesAverage() << " s" << endl;
    cout << "DFS N: "<<'\t';
    cout << fixed << StoperDFS.SeriesAverage() << " s" << endl;
    StoperBFS.SaveAverageTimeToBuffer(StoperBFS.SeriesAverage());
    StoperDFS.SaveAverageTimeToBuffer(StoperBFS.SeriesAverage());
    StoperBFS.DumpToFile(nazwaPlikuBFS, StoperBFS.SeriesAverage());
    StoperDFS.DumpToFile(nazwaPlikuDFS, StoperDFS.SeriesAverage());
    StoperBFS.CleanElapsedTimes();
    StoperDFS.CleanElapsedTimes();
  } // pierwszy for
 // 
  /*
  srand(time(NULL));
  Graph G(100000);
 
  for(int i=0; i<G.maxN(); ++i)
    G.insertVertex(i);
  
  unsigned* tmp = new unsigned int[G.maxN()];
  for(int i=0; i<G.maxN(); ++i)
    tmp[i] = i;

  for(int i=0; i<G.maxN()-1;++i)
    swap(tmp[i],tmp[rand()%G.maxN()]);
//generowanie spójnego grafu

  for(int i=0; i<G.maxN()-1; ++i) 
   G.insertEdge(tmp[i], tmp[i+1]);
  
  if(tmp!= NULL)
   delete [] tmp;
 
  unsigned beginning, end;
  
  for(int i=0; i<G.maxN(); ++i){
    beginning = rand() % G.maxN();
    end = rand() % G.maxN();
    G.insertEdge(beginning, end);
  }
  G.Print();
  
 // G.neighbours(5)->Print();
  cout << endl;
  cout << "*********" << endl;
  cout << "**** DFS *****" << endl;
  G.DFS(0);
  cout << endl;
  //G.neighbours(1)->Print();
  //G.Print();
  cout << "**** BFS *****" << endl;
  G.BFS(0);
  cout << endl;
*/
  return 0;
}