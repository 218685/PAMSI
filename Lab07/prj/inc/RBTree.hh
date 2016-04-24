#ifndef RBTREE_HH
#define RBTREE_HH

#include <iostream>
#include <string>
#include "TreeNode.hh"
#include "IBinaryTree.hh"
using namespace std;

/*!
 * \file RBTree.hh
 *
 *  Plik zawiera definicję klasy implementującej drzewo binarne.
 */

/*!
 * \brief Szablonowa klasa implementująca drzewo binarne czerwono-czarne
 *
 * Drzewo jest zbudowana w oparciu o węzły TreeNode.
 * Może przechowywać dowolny typ danych dzięki zastosowaniu
 * szablonu.
 */
template <typename Object>
class RBTree : public IBinaryTree<Object>
{
protected:
  TreeNode<Object> S;     /*!< wartownik */
  TreeNode<Object>* root; /*!< wskaźnik na korzeń */
public:
/*!
 * \brief Konstruktor listy jednokierunkowaj
 *
 * Ustawia kolor wartownika na czarny i przypisuje 
 * wartownika do roota.
 */
  RBTree();
/*!
 * \brief Destruktor listy jednokierunkowaj
 *
 * Usuwa drzewo poprzez rekurencyjne wywołanie metody Clear().
 */
  ~RBTree();

/*!
 * \brief Metoda sprawdzająca, czy drzewo jest puste
 *
 * Sprawdza, czy root wskazuje na NULL.
 * \retval true - jeśli jest puste
 * \retval false - jeśli nie jest puste;
 */
  virtual bool IsEmpty();
 
/*!
 * \brief Metoda usuwająca rekurencyjnie podany węzeł
 *
 * Usuwa synów (jeśli istnieją) oraz sam podany węzeł.
 * \param[in] v - węzeł do usunięcia
 */
  void Clear(TreeNode<Object>* v);
  
/*!
 * \brief Metoda drukująca drzewo na standardowe wyjście
 *
 * Dane węzłów wyświetlane są w porządku in order.
 * \param[in] v - węzeł, od którego ma zacząć  
 */
  void PrintAll(TreeNode<Object>* v);

/*!
 * \brief Metoda zwracająca referencję do wartownika
 * \return Referencja do wartownika.
 */
  TreeNode<Object>& SGuard();
  
/*!
 * \brief Metoda zwracająca korzeń
 * \return Wskaźnik do korzeńia.
 */
  TreeNode<Object>* & Root();
  
  TreeNode<Object>* Find(Object item);
  
/*!
 * \brief Metoda znajdująca największy następnik podanego elementu
 * \param[in] v - węzeł, od którego ma zacząć 
 * \return Wskaźnik do elementu największego. 
 */
  TreeNode<Object>* Max(TreeNode<Object>* v);
  
/*!
 * \brief Metoda znajdująca najmniejszy następnik podanego elementu
 * \param[in] v - węzeł, od którego ma zacząć 
 * \return Wskaźnik do elementu najmniejszego. 
 */
  TreeNode<Object>* Min(TreeNode<Object>* v);
 
/*!
 * \brief Metoda znajdująca następnik podanego węzła
 * 
 * \param[in] v - węzeł, od którego ma zacząć  
 * \return Wskaźnik do następnika. 
 */
  TreeNode<Object>* Successor(TreeNode<Object>* v);
  
/*!
 * \brief Wykonuje rotację w prawo
 * 
 * \param[in] v - węzeł, od którego ma zacząć  
 */
  void RotateRight(TreeNode<Object>* v);
  
/*!
 * \brief Wykonuje rotację w lewo
 * 
 * \param[in] v - węzeł, od którego ma zacząć  
 */
  void RotateLeft(TreeNode<Object>* v);
  
/*!
 * \brief Dodaje nowy element do drzewa
 * 
 * Tworzy nowy węzeł o podanej wartości, szuka miejsca do dodania.
 * W razie potrzeby wykonuje balansowanie drzewa metodologią
 * czerwono-czarną.
 * \param[in] newItem - wartość nowego węzła do dodania 
 */
  virtual void Insert(const Object newItem);
  
 /*!
 * \brief Usuwa podany element z drzewa
 * 
 * Wyszukuje węzeł o podanej wartości na drzewie.
 * Jeśli istnieje, to uruchamiana jest procedura usuwania.
 * Po usunięciu przeprowadzane jest balansowanie drzewa 
 * metodologią  czerwono-czarną.
 * \param[in] item - wartość do usunięcia
 */
  virtual void Remove(Object item);
};

template <typename Object>
RBTree<Object>::RBTree(){

  S.Color() = 'B';
  S.Left() = S.Right() = S.Parent() = NULL;
  root = &S;
}

template <typename Object>
RBTree<Object>::~RBTree(){

  Clear(root);
}

template <typename Object>
bool RBTree<Object>::IsEmpty(){

  return (root == NULL) ? true : false;
}

template <typename Object>
void RBTree<Object>::Clear(TreeNode<Object>* v){
  
  if(v != NULL && v!= &S ){
    Clear( v->Left() );
    Clear( v->Right() );
    delete v;
    //cout << "wyczyszczono ";
    }
}

template <typename Object>
void RBTree<Object>::PrintAll(TreeNode<Object>* v){

  if (v == NULL)
    cout << "RBT: Pusto!" << endl;
  if (v != NULL && v!= &S){
    PrintAll(v->Left());
    cout << v->Element() <<" ";
    PrintAll(v->Right());
    }
}

template <typename Object>
TreeNode<Object>& RBTree<Object>::SGuard(){
  
  return S;
}

template <typename Object>
TreeNode<Object>* & RBTree<Object>::Root(){

  return root;
}

template <typename Object>
TreeNode<Object>* RBTree<Object>::Find(Object item){

  TreeNode<Object>* x = root;
  while (x!=&S && x->Element()!=item)
    if(item < x->Element())
      x = x->Left();
    else
      x = x->Right();

  if(x == &S)
    return NULL;

  return x;
}

template <typename Object>
TreeNode<Object>* RBTree<Object>::Max(TreeNode<Object>* v){

  while (v!= &S && v->Right()!=&S)
    v = v->Right();

  return v;
}

template <typename Object>
TreeNode<Object>* RBTree<Object>::Min(TreeNode<Object>* v){

  while (v!=&S && v->Left()!=&S)
    v = v->Left();

  return v;
}

template <typename Object>
TreeNode<Object>* RBTree<Object>::Successor(TreeNode<Object>* v)
{
  TreeNode<Object>* x;

  if(v != &S){
    if(v->Right() != &S)
      return Min(v->Right());
    else{
      x = v->Parent();
      while(x!=&S && v == x->Right()) {
        v = x;
        x = x->Parent();
      }
      return x;
    }
  }
  return &S;
}

template <typename Object>
void RBTree<Object>::RotateRight(TreeNode<Object>* v){

  TreeNode<Object>* y, *b;
  b = v->Left();

  if(b != &S){
    y = v->Parent();
  //zamień lewe poddrzewo y na prawe poddrzewo x
    v->Left() = b->Right();
    if(v->Left() != &S)
     v->Left()->Parent() = v;

    b->Right() = v;
    b->Parent() = y;
    v->Parent() = b;

    if(y != &S){
      if(y->Left() == v)
        y->Left() = b;
      else
        y->Right() = b;
      }
    else
      root =b;
  }
}

template <typename Object>
void RBTree<Object>::RotateLeft(TreeNode<Object>* v){

  TreeNode<Object>* y, *b;
  b = v->Right();

  if(b != &S){
    y = v->Parent();
  //zamień lewe poddrzewo y na prawe poddrzewo x
    v->Right() = b->Left();
    if(v->Right() != &S)
     v->Right()->Parent() = v;

    b->Left() = v;
    b->Parent() = y;
    v->Parent() = b;

    if(y != &S){
      if(y->Left() == v)
        y->Left() = b;
      else
        y->Right() = b;
      }
    else
      root =b;
  }
}

template <typename Object>
void RBTree<Object>::Insert(const Object newItem){

  TreeNode<Object> * X, * Y;

  X = new TreeNode<Object>;        // Tworzymy nowy węzeł
  X->Left() = &S;          // Inicjujemy pola
  X->Right() = &S;
  X->Parent() = root;
  X->Element() = newItem;
  if(X->Parent() == &S) 
    root = X; // X staje się korzeniem
  else{
  while(true)             // Szukamy liścia do zastąpienia przez X
  {
    if(newItem < X->Parent()->Element()){
      if(X->Parent()->Left() == &S){
        X->Parent()->Left() = X;  // X zastępuje lewy liść
        break;
      }
      X->Parent() = X->Parent()->Left();
    }
    else{
      if(X->Parent()->Right() == &S){
        X->Parent()->Right() = X; // X zastępuje prawy liść
        break;
      }
      X->Parent() = X->Parent()->Right();
    }
  }
 
  X->Color() = 'R';         // Węzeł kolorujemy na czerwono
  while(X!=root && X->Parent()->Color() == 'R'){
    if(X->Parent() == X->Parent()->Parent()->Left()){
      Y = X->Parent()->Parent()->Right(); // Y -> wujek X
// 1*
      if(Y->Color() == 'R'){
        X->Parent()->Color() = 'B';
        Y->Color() = 'B';
        X->Parent()->Parent()->Color() = 'R';
        X = X->Parent()->Parent();
      }
      else{
      //2*
        if(X == X->Parent()->Right()){
          X = X->Parent();
          RotateLeft(X);
        }

      X->Parent()->Color() = 'B'; // Przypadek 3
      X->Parent()->Parent()->Color() = 'R';
      RotateRight(X->Parent()->Parent());
      }
    }
    else{                  // Przypadki lustrzane
      Y = X->Parent()->Parent()->Right();

      if(Y->Color() == 'R') // Przypadek 1
      {
        X->Parent()->Color() = 'B';
        Y->Color() = 'B';
        X->Parent()->Parent()->Color() = 'R';
        X = X->Parent()->Parent();
      }
      else{
        if(X == X->Parent()->Left()) // Przypadek 2
        {
          X = X->Parent();
          RotateRight(X);
        }

        X->Parent()->Color() = 'B'; // Przypadek 3
        X->Parent()->Parent()->Color() = 'R';
        RotateLeft(X->Parent()->Parent());
      }
    }//lustrzane przypadki
   }//while
  }//else
  root->Color() = 'B';
}

template <typename Object>
void RBTree<Object>::Remove(Object item){
  //szukamy elementu o wartości item
  TreeNode<Object>* v = Find(item);
//jesli istenieje taki węzeł
 if(v != &S){
  TreeNode<Object>* y, * x,  *w;
  if(v->Left() == &S || v->Right() == &S)
    y = v;
  else
    y = Successor(v);

  if(y->Left() != &S)
    x = y->Left();
  else
    x = y->Right();

  x->Parent() = y->Parent();

  if(y->Parent() == &S)
    Root() = x;
  else
    if (y == y->Parent()->Left())
      y->Parent()->Left() = x;
    else
      y->Parent()->Right() = x;

  if( y!=v )
    v->Element() = y->Element();

  if(y->Color() == 'B'){
  //przywracanie własności BRT

    while(x!=Root() && x->Color() == 'B'){
      if(x == x->Parent()->Left()){
        w = x->Parent()->Right();
      //przypadek 1
        if(w->Color() == 'R'){
          w->Color() = 'B';
          x->Parent()->Color() = 'R';
          RotateLeft(x->Parent());
          w = x->Parent()->Right();
          }
      //przypadek 2
        if((w->Left())->Color() == 'B' && (w->Right())->Color() == 'B'){
          w->Color() = 'R';
          x = x->Parent();
          continue;
          }

      //przypadek 3
        if(w->Right()->Color() == 'B'){
          w->Left()->Color() = 'B' ;
          w->Color() = 'R';
          RotateRight(w);
          w = x->Parent()->Right();
          }
        //przypadek 4
          w->Color() = x->Parent()->Color();
          x->Parent()->Color() = 'B';
          w->Right()->Color() = 'B';
          RotateLeft(x->Parent());
          x = Root();

        }//pierwszy if
    //przypadki lustrzane
      else{
        w = x->Parent()->Left();
      //przypadek 1
        if(w->Color() == 'R'){
          w->Color() = 'B';
          x->Parent()->Color() = 'R';
          RotateRight(x->Parent());
          w = x->Parent()->Left();
          }
      //przypadek 2
        if(w->Right()->Color() == 'B' && w->Left()->Color() == 'B'){
          w->Color() = 'R';
          x = x->Parent();
          continue;
          }
      //przypadek 3
        if(w->Left()->Color() == 'B'){
          w->Right()->Color() = 'B' ;
          w->Color() = 'R';
          RotateLeft(w);
          w = x->Parent()->Left();
          }
      //przypadek 4
        w->Color() = x->Parent()->Color();
        x->Parent()->Color() = 'B';
        w->Left()->Color() = 'B';
        RotateRight(x->Parent());
        x = Root();

      }//koniec else
    }//while
    x->Color() = 'B';
    }

  delete y;
  }
}

#endif
