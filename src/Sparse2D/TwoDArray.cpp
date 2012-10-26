#include "TwoDArray.h"
#include <cassert>
#include <iostream>
#include <string>
#include "Node.h"

using std::cout;
using std::endl;

template <typename T>
void TwoDArray<T>::deleteAllNodesRight(Node<T>* n) {
/*  if (n==0) {  // base case
    delete n;
    return;
  }
  else { // recursive case   
    Node<T>* tmp=n;
    n=n->getNextRight();
    deleteAllNodesRight(n);
    delete tmp;
  } */
}

template <typename T>
Node<T>* TwoDArray<T>::getPrevLeft(int r, int c) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<columns);
  
  Node<T>* curr=rowArray[r];
  
  if (curr==0) return curr;
  else {
    while(curr->getNextRight()!=0 && curr->getNextRight()->getCol()<c) {
      curr=curr->getNextRight();
    }
  }
  // cout << curr->getCol() << endl;
  return curr;
}

template <typename T>
Node<T>* TwoDArray<T>::getPrevUp(int r, int c) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<columns);
  
  Node<T>* curr=colArray[c];
  
  if (curr==0) return curr;
  else {
    while(curr->getNextDown()!=0 && curr->getNextDown()->getRow()<r) {
      curr=curr->getNextDown();
    }
  }
  // cout << curr->getRow() << endl;
  return curr;
}

template <typename T>
bool TwoDArray<T>::find(int r, int c) {
  
  Node<T>* prevLeft=getPrevLeft(r,c);
  Node<T>* prevUp=getPrevUp(r,c);

  if (prevLeft->getNextRight()->getCol()==c && prevUp->getNextDown()->getRow()==r) {
    return true;
  } else return false;
}

template <typename T>
T TwoDArray<T>::findValue(int r, int c) {
  
  Node<T>* prevLeft=getPrevLeft(r,c);
  Node<T>* prevUp=getPrevUp(r,c);

  if (prevLeft->getNextRight()->getCol()==c && prevUp->getNextDown()->getRow()==r) {
    return prevLeft->getNextRight()->getValue();
  } else return defaultValue;
}

 
template <typename T> 
TwoDArray<T>::TwoDArray(int r, int c, T def) {
  assert(r>0 && c>0);
  rows=r;
  columns=c;
  defaultValue=def;

  rowArray=new Node<T>*[rows];
  colArray=new Node<T>*[columns];

  for (int i=0; i<rows; i++) {
    rowArray[i]=0;
  }

  for (int j=0; j<columns; j++) {
    colArray[j]=0;
  }

}
  
template <typename T>
TwoDArray<T>::~TwoDArray() {
  delete [] colArray;
  //for (int i=0; i<rows; i++) {
  //  deleteAllNodesRight(rowArray[i]);
  //}
  delete [] rowArray;
}

template <typename T>
void TwoDArray<T>::insert(int r, int c, T val) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<columns);

  Node<T>* prevLeft=getPrevLeft(r,c);

  if (find(r,c)) {
    prevLeft->getNextRight()->setValue(val);
    return;
  } else 
  {
    Node<T>* prevUp=getPrevUp(r,c);
    Node<T>* newNode=new Node<T>(val,r,c);
    newNode->setNextRight(*(prevLeft->getNextRight()));
    newNode->setNextDown(*(prevUp->getNextDown()));
    prevLeft->setNextRight(*newNode);
    prevUp->setNextDown(*newNode);
  }
}
    
template <typename T>
T TwoDArray<T>::access(int r, int c) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<columns);

  if (find(r,c)) {
    Node<T>* prevLeft=getPrevLeft(r,c);
    return prevLeft->getNextRight()->getValue();
  } else {
    return defaultValue;
  }
}

template <typename T>
void TwoDArray<T>::remove(int r, int c) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<columns);

  if (find(r,c)) {
    Node<T>* prevLeft=getPrevLeft(r,c);
    Node<T>* prevUp=getPrevUp(r,c);
    Node<T>* curr=prevLeft->getNextRight();
    prevLeft->setNextRight(*(curr->getNextRight()));
    prevUp->setNextDown(*(curr->getNextDown()));
    delete curr;
  }
}

template <typename T>
void TwoDArray<T>::print() {

  for (int i=0; i<rows; i++) {
    cout << "[ ";
    for (int j=0; j<columns; j++) {
        cout << access(i,j);
        if (j<columns-1) cout << ", ";
    } 
    cout << " ]" << endl;
  }
}

template <typename T>
int TwoDArray<T>::getNumRows() {
  return rows;
}
    
template <typename T>
int TwoDArray<T>::getNumCols() {
  return columns;
}

template class TwoDArray<int>;
template class TwoDArray<double>;
template class TwoDArray<std::string>;

