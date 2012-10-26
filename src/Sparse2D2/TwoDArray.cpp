#include "TwoDArray.h"
#include <cassert>
#include <iostream>
#include <string>
#include "Node.h"
#include "LinkedList.h"

using std::cout;
using std::endl;

template <typename T>
void TwoDArray<T>::deleteAllNodesRight(Node<T>* n) {
  if (n==0) {  // base case
    delete n;
    return;
  }
  else { // recursive case   
    Node<T>* tmp=n;
    n=n->getNextRight();
    deleteAllNodesRight(n);
    delete tmp;
  } 
}

template <typename T>
Node<T>* TwoDArray<T>::getPrevLeft(int r, int c) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<columns);
 
  int currElements=(rowArray[r]->getSize()); 
  Node<T>* curr;

  if (currElements==0) return 0;
  else {
    
    curr=(rowArray[r])->getHead();
    while(curr->getNextRight()!=0) {
      if (curr->getNextRight()->getCol()>=c) 
        return curr;
      else 
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
  
  
  int currElements=(colArray[c]->getSize()); 
  Node<T>* curr;

  if (currElements==0) return 0;
  else {

    curr=(colArray[c])->getHead();
    while(curr->getNextDown()!=0) {
      if (curr->getNextDown()->getRow()>=r) 
        return curr;
      else
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
  
  if (prevLeft==0 || prevUp==0) return false;
  else
    if (prevLeft->getNextRight()->getCol()==c && prevUp->getNextDown()->getRow()==r) {
    return true;
  } else return false;
}

/* template <typename T>
T TwoDArray<T>::findValue(int r, int c) {
  
  Node<T>* prevLeft=getPrevLeft(r,c);
  Node<T>* prevUp=getPrevUp(r,c);

  if (prevLeft->getNextRight()->getCol()==c && prevUp->getNextDown()->getRow()==r) {
    return prevLeft->getNextRight()->getValue();
  } else return defaultValue;
}
*/
 
template <typename T> 
TwoDArray<T>::TwoDArray(int r, int c, T def) {
  assert(r>0 && c>0);
  rows=r;
  columns=c;
  defaultValue=def;

  rowArray=new LinkedList<T>*[rows];
  colArray=new LinkedList<T>*[columns];


  for (int i=0; i<rows; i++) {
    rowArray[i]=new LinkedList<T>();    
//(rowArray[i])->setHead(0);
 //   cout << rowArray[i].getSize() << endl;
  }

  for (int j=0; j<columns; j++) {
    colArray[j]=new LinkedList<T>(); 
   //(colArray[j])->setHead(0);
   // cout << colArray[j].getSize() << endl;
  }

}
  
template <typename T>
TwoDArray<T>::~TwoDArray() {
/*  delete [] colArray;
  for (int i=0; i<rows; i++) {
    deleteAllNodesRight(rowArray[i]);
  }
*/  //delete [] rowArray;
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
   
    if (prevLeft==0) {
      (rowArray[r])->setHead(newNode);
    } else {
      newNode->setNextRight(prevLeft->getNextRight());
      prevLeft->setNextRight(newNode);
    }
    
    if (prevUp==0) {
      (colArray[c])->setHead(newNode);
    } else {
      newNode->setNextDown(prevUp->getNextDown());
      prevUp->setNextDown(newNode);
    }  
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

  if (!find(r,c)) return;
  else {

    Node<T>* prevLeft=getPrevLeft(r,c);
    Node<T>* curr;
    Node<T>* prevUp=getPrevUp(r,c);

    if (prevLeft==0) {
      curr=(rowArray[r])->getHead();
      (rowArray[r])->setHead(curr->getNextRight());
      // (rowArray[r])->setSize(0);
    } else {
      curr=prevLeft->getNextRight();
      prevLeft->setNextRight(curr->getNextRight());
    }

    if (prevUp==0) {
      (colArray[c])->setHead(curr->getNextDown());
    } else {
      prevUp->setNextDown(curr->getNextDown());  
    }

    delete curr;

    (rowArray[r])->setSize(((rowArray[r])->getSize())-1);
    (colArray[c])->setSize(((colArray[r])->getSize())-1);
    }
/*
    Node<T>* prevLeft=getPrevLeft(r,c);
    Node<T>* prevUp=getPrevUp(r,c);
    Node<T>* curr=prevLeft->getNextRight();
    prevLeft->setNextRight(curr->getNextRight());
    prevUp->setNextDown(curr->getNextDown());
    delete curr;
*/
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

