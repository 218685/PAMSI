#ifndef TREENODE_HH
#define TREENODE_HH

#include <iostream>
using namespace std;

template < typename Object >
class TreeNode  // wezel drzewa binarnego
{
private:
  //unsigned key;
  Object item;      // element wezla
  char color;
  TreeNode<Object>* parent;  // wskazniki do ojca, lewego syna, prawego syna
  TreeNode<Object>* left;
  TreeNode<Object>* right;
public:
  TreeNode() { parent = left = right = NULL; /*key = 0;*/ }
  ~TreeNode() { parent = left = right = NULL; }
  TreeNode(Object newItem) { parent = left = right = NULL; item = newItem; } //key = 0;}
  Object & Element() { return item; }
  //unsigned & Key() { return key; }
  char & Color() {return color;}
  TreeNode<Object>* & Parent() { return parent; }
  TreeNode<Object>* & Left() { return left; }
  TreeNode<Object>* & Right() { return right; }

};


#endif
