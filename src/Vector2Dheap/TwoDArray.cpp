#include "TwoDArray.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

template <typename T> 
TwoDArray<T>::TwoDArray(int r, int c, T def) {
  assert(r>0 && c>0);
  
  defaultValue=def;
  theVector=new std::vector<std::vector<T> >(r,std::vector<T>(c,defaultValue));
}
  
template <typename T>
TwoDArray<T>::~TwoDArray() {
  delete theVector;
}

template <typename T>
void TwoDArray<T>::insert(int r, int c, T val) {
  assert(r>=0 && r<getNumRows());
  assert(c>=0 && c<getNumCols());

  (*theVector)[r][c]=val;
}
    
template <typename T>
T TwoDArray<T>::access(int r, int c) {
  assert(r>=0 && r<getNumRows());
  assert(c>=0 && c<getNumCols());

  return (*theVector)[r][c];
}

template <typename T>
void TwoDArray<T>::remove(int r, int c) {
  assert(r>=0 && r<getNumRows());
  assert(c>=0 && c<getNumCols());

  (*theVector)[r][c]=defaultValue;
}

template <typename T>
void TwoDArray<T>::print() {

  for (int i=0; i<getNumRows(); i++) {
    cout << "[ ";
    for (int j=0; j<getNumCols(); j++) {
      cout << (*theVector)[i][j];
      if (j<getNumCols()-1) cout << ", ";
    } 
    cout << " ]" << endl;
  }
  cout << endl;
}

template <typename T>
int TwoDArray<T>::getNumRows() {
  return theVector->size();
}
    
template <typename T>
int TwoDArray<T>::getNumCols() {
  return (*theVector)[0].size();
}

template class TwoDArray<int>;
template class TwoDArray<double>;
template class TwoDArray<std::string>;

