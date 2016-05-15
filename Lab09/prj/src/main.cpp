#include <iostream>
//#include "Graph.hh"
#include "Graph_Test.hh"
#include "AdvancedStopwatch.hh"
using namespace std;

int main()
{
  srand(time(NULL));
  Graph_Test<int> G;
  
  AdvancedStopwatch  StoperBB;
  AdvancedStopwatch  StoperBBEL;
  
  int nSize[6] = {10,100,1000,10000,100000,1000000};
//nazwy plików do pracy
  string nazwaPlikuBB = "Branch&Bound";
  string nazwaPlikuBBEL = "Branch&BoundExtendedList";
//różne wielkości problemów
  for(int j=5; j<6; ++j){
  //przygotowanie grafu
    cout << "******************" << endl;
    G.Prepare(nSize[j]);
    cout << "N: " << setw(7) << nSize[j] << endl;
    for(int i=0; i<1; ++i){
      //G.Prepare(nSize[j]);
      G.RandomPathEnd();
      //standard branch & bound
      G.changeSearchType('S');    
      StoperBB.Start();
      G.Run();
      StoperBB.Stop();
      StoperBB.SaveElapsedTime(StoperBB.GetElapsedTime());
   //with extended list
      G.changeSearchType('E');
      StoperBBEL.Start();
      G.Run();
      StoperBBEL.Stop();
      StoperBBEL.SaveElapsedTime(StoperBBEL.GetElapsedTime());
    }//środkowy for - seria 10 pomiarów
  //wyswietlenie średnich czasów
    cout << endl << "B&B "<< nSize[j]<< ": "<<'\t';
    cout << fixed << StoperBB.SeriesAverage() << " s" << endl;
    cout << "B&B EL "<<nSize[j] << ": "<<'\t';
    cout << fixed << StoperBBEL.SeriesAverage() << " s" << endl;
    StoperBB.SaveAverageTimeToBuffer(StoperBB.SeriesAverage());
    StoperBBEL.SaveAverageTimeToBuffer(StoperBBEL.SeriesAverage());
    StoperBB.DumpToFile(nazwaPlikuBB, StoperBB.SeriesAverage());
    StoperBBEL.DumpToFile(nazwaPlikuBBEL, StoperBBEL.SeriesAverage());
    StoperBB.CleanElapsedTimes();
    StoperBBEL.CleanElapsedTimes();
  } // pierwszy for

  return 0;
}

 /*
  srand(time(NULL));
  Graph G(1000);
 
  for(int i=0; i<G.maxN(); ++i)
    G.insertVertex(i);
    /*
  G.insertEdge(1, 2, 3);
  G.insertEdge(2, 3, 3);
  G.insertEdge(2, 5, 4);
  G.insertEdge(3, 4, 5);
  G.insertEdge(1, 5, 5);
  G.insertEdge(5, 6, 4);
  G.insertEdge(6, 7, 6);
  
  
  unsigned* tmp = new unsigned int[G.maxN()];
  for(int i=0; i<G.maxN(); ++i)
    tmp[i] = i;
   
  for(int i=0; i<G.maxN()-1;++i)
    swap(tmp[i],tmp[rand()%G.maxN()]);
//generowanie spójnego grafu
  for(int i=0; i<G.maxN()-1; ++i) 
   G.insertEdge(tmp[i], tmp[i+1], rand()%10+1);

  if(tmp!= NULL)
   delete [] tmp;
 
  unsigned beginning, end;
  
  for(int i=0; i<2*G.maxN(); ++i){
    beginning = rand() % G.maxN();
    end = rand() % G.maxN();
    G.insertEdge(beginning, end, rand()%10+1);
  }
  //G.Print();
  unsigned finish = rand() % G.maxN() +1;
  G.BestFirstBranchBound(1,finish);
  cout << endl << "Zwykły ********* " << endl;
  G.BranchBound(1, finish);
  */