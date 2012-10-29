#include "TwoDArray.h"
#include <cassert>
#include <iostream>
#include <string>
#include "Node.h"
#include "LinkedList.h"

using std::cout;
using std::endl;


template <typename T>
Node<T>* TwoDArray<T>::findNode(int r, int c) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<columns);

  int rListSize=rowArray[r]->getSize();
  int cListSize=colArray[c]->getSize();
  Node<T>* curr=0;

  if (rListSize==0 || cListSize==0)
    return 0;
  else if (rListSize<=cListSize) {
    curr=rowArray[r]->getHead();
    while (curr!=0) {
      if (curr->getCol()==c)
        return curr;
      else if (curr->getCol()>c)
        return 0;
      else curr=curr->getNextRight();
    }
    return 0;
  }
  else {
    curr=colArray[c]->getHead();
    while (curr!=0) {
      if (curr->getRow()==r)
        return curr;
      else if (curr->getRow()>r)
        return 0;
      else curr=curr->getNextDown();
    }
    return 0;
  }
} 

template <typename T>
bool TwoDArray<T>::getNodes(int r, int c, Node<T>* &pLeft, Node<T>* &pUp) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<columns);

  int rListSize=rowArray[r]->getSize();
  int cListSize=colArray[c]->getSize();
  Node<T>* curr=0;
  bool result=false;

  if (rListSize>0) {
    curr=rowArray[r]->getHead();
    while (curr!=0 && curr->getCol()<c) {
      pLeft=curr;
      curr=curr->getNextRight();
    }
    if (curr==0)
      result=false;
    else if (curr->getCol()==c)
      result=true;
    else 
      result=false;
  }

  if (cListSize>0) {
    curr=colArray[c]->getHead();
    while(curr!=0 && curr->getRow()<r) {
      pUp=curr;
      curr=curr->getNextDown();
    }
  }
  return result;
} 

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
  }

  for (int j=0; j<columns; j++) {
    colArray[j]=new LinkedList<T>(); 
  }
}
  
template <typename T>
TwoDArray<T>::~TwoDArray() {

  Node<T>* curr=0;
  Node<T>* tmp=0;

  for (int i=0;i<rows;i++) {
    if (!(rowArray[i]->isEmpty())) {
      curr=rowArray[i]->getHead();
      while (curr!=0) {
        tmp=curr;
        curr=curr->getNextRight();
        delete tmp;
      }
    }
  }

  for (int j=0;j<rows;j++) {
    delete rowArray[j];
  }
  
  for (int k=0;k<columns;k++) {
    delete colArray[k];
  }  
  
  delete [] rowArray;
  delete [] colArray;
}

template <typename T>
void TwoDArray<T>::insert(int r, int c, T val) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<columns);

  Node<T>* pLeft=0;
  Node<T>* pUp=0;
  Node<T>* newNode=0;

  if (getNodes(r,c,pLeft,pUp)) {
    if (pLeft==0)
      rowArray[r]->getHead()->setValue(val);
    else
      pLeft->getNextRight()->setValue(val);
    return;
  }

  else {
    newNode=new Node<T>(val,r,c);
    if (pLeft==0) {
      if (rowArray[r]->isEmpty())
        rowArray[r]->setHead(newNode);
      else {
        newNode->setNextRight(rowArray[r]->getHead());
        rowArray[r]->setHead(newNode);
      }
    }
    else {
      newNode->setNextRight(pLeft->getNextRight());
      pLeft->setNextRight(newNode);
    }
  }
  rowArray[r]->setSize((rowArray[r]->getSize())+1);

  if (pUp==0) {
    if (colArray[c]->isEmpty())
      colArray[c]->setHead(newNode);
    else {
      newNode->setNextDown(colArray[c]->getHead());
      colArray[c]->setHead(newNode);
    }
  }
  else {
    newNode->setNextDown(pUp->getNextDown());
    pUp->setNextDown(newNode);
  }
  colArray[c]->setSize((colArray[c]->getSize())+1);

}
    
template <typename T>
T TwoDArray<T>::access(int r, int c) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<columns);
 
  Node<T>* curr=findNode(r,c);
  if (curr==0)
    return defaultValue;
  else
    return curr->getValue();  
}

template <typename T>
void TwoDArray<T>::remove(int r, int c) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<columns);

  Node<T>* pLeft=0;
  Node<T>* pUp=0;
  Node<T>* curr=0;

  if (!getNodes(r,c,pLeft,pUp)) 
    return;
  
  if (pLeft==0) {
    curr=rowArray[r]->getHead();
    rowArray[r]->setHead(curr->getNextRight());
  }
  else {
    curr=pLeft->getNextRight();
    pLeft->setNextRight(curr->getNextRight());
  }
  rowArray[r]->setSize((rowArray[r]->getSize())-1);

  if (pUp==0) {
    colArray[c]->setHead(curr->getNextDown());
  }
  else {
    pUp->setNextDown(curr->getNextDown());
  }
  colArray[c]->setSize((colArray[c]->getSize())-1);
  
  delete curr;
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
  cout << endl;
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

