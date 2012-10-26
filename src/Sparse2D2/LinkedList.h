#ifndef __LLIST_H__
#define __LLIST_H__

#include "Node.h"

template <typename T>
class LinkedList {
  private:
    Node<T>* head;
    int numElements;

  public:
    LinkedList<T>();
    LinkedList<T>(Node<T>* h, int nE);
    ~LinkedList<T>();
    
    Node<T>* getHead();
    void setHead(Node<T>* h);
    int getSize();
    void setSize(int nE);
    bool isEmpty();
    
    /*
    T getValue();
    void setValue(T v);
    int getRow();
    int getCol();
    Node<T>* getNextRight();
    Node<T>* getNextDown();
    void setNextRight(Node<T>* n);
    void setNextDown(Node<T>* n);
    */
};
#endif

