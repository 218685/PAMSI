#include <iostream>
#include "BTreeTab.hh"
using namespace std;

int main()
{
  BTreeTab<int> drzewo(10);

  drzewo.Insert(5);
  drzewo.Insert(6);
  drzewo.Insert(3);
  drzewo.PreOrder(1);

  return 0;

}
