#ifndef __TWODARRAY_H__
#define __TWODARRAY_H__

#include "Node.h"
#include "LinkedList.h"

template <typename T>
class TwoDArray {

  private:
    int rows;  // total # of rows
    int columns;  // total # of columns
    T defaultValue;
    LinkedList<T>** rowArray; //array of LinkedList<T> pointers
    LinkedList<T>** colArray; //array of LinkedList<T> pointers
    
    void deleteAllNodesRight(Node<T>* n);  // private helper methods
    Node<T>* getPrevLeft(int r, int c);
    Node<T>* getPrevUp(int r, int c);
    bool find(int r, int c);
    // T findValue(int r, int c);

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
