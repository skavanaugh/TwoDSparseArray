#ifndef __TWODARRAY_H__
#define __TWODARRAY_H__

#include <vector>

template <typename T>
class TwoDArray {

  private:
    T defaultValue;
    std::vector<std::vector<T> > theVector;
    
  public:
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
