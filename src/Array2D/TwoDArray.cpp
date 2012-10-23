#include "TwoDArray.h"
#include <cassert>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

/* template <typename T>
TwoDArray<T>::TwoDArray() {
  rows=10;
  columns=10;
  defaultValue=0;

  theArray=new T*[rows];
      
  for (int i=0; i<rows; i++) {
    theArray[i]=new T[columns];
  }

  for (int i=0; i<rows; i++) {
    for (int j=0; j<columns; j++) {
      theArray[i][j]=defaultValue;
    }
  }
} */
 
template <typename T> 
TwoDArray<T>::TwoDArray(int r, int c, T def) {
  assert(r>0 && c>0);
  rows=r;
  columns=c;
  defaultValue=def;

  theArray=new T*[rows];
      
  for (int i=0; i<rows; i++) {
    theArray[i]=new T[columns];
  }

  for (int i=0; i<rows; i++) {
    for (int j=0; j<columns; j++) {
      theArray[i][j]=defaultValue;
    }
  }
}
  
template <typename T>
TwoDArray<T>::~TwoDArray() {
  for (int i=0; i<rows; i++) {
    delete [] theArray[i];
  }
  delete [] theArray;
}

template <typename T>
void TwoDArray<T>::insert(int r, int c, T val) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<columns);

  theArray[r][c]=val;
  
  // deal with resizing theArray if r>=rows and/or c>=columns
}
    
template <typename T>
T TwoDArray<T>::access(int r, int c) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<columns);

  return theArray[r][c];
}

template <typename T>
void TwoDArray<T>::remove(int r, int c) {
  assert(r>=0 && r<rows);
  assert(c>=0 && c<columns);

  theArray[r][c]=defaultValue;
}

template <typename T>
void TwoDArray<T>::print() {

  for (int i=0; i<rows; i++) {
    cout << "[ ";
    for (int j=0; j<columns; j++) {
      cout << theArray[i][j];
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

