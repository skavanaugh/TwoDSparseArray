#ifndef __TWODARRAY_H__
#define __TWODARRAY_H__

#include "Node.h"

template <typename T>
class TwoDArray {

  private:
    int rows;
    int columns;
    T defaultValue;
    Node<T>* rowArray;
    Node<T>* colArray;
  
  public:
    //TwoDArray<T>();
    TwoDArray<T>(int r, int c, T def);
    ~TwoDArray<T>();
    void insert(int r, int c, T value);
    T access(int r, int c);
    void remove(int r, int c);
    void print();
    int getNumRows();
    int getNumCols();
};

#endif
