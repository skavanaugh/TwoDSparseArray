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
    
    //void deleteAllNodesRight(Node<T>* n);  // private helper methods
    //Node<T>* getPrevLeft(int r, int c);
    //Node<T>* getPrevUp(int r, int c);
    Node<T>* findNode(int r, int c); // returns a ptr to the Node at (r,c)
    // getNodes returns true if there is a Node (curr) at (r,c).
    // pLeft is a ptr to the Node just left of curr (or where curr would be).
    // pUp is a ptr to the node just up from curr (or where curr would be)
    bool getNodes(int r, int c, Node<T>*& pLeft, Node<T>*& pUp);
    // T findValue(int r, int c);

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
