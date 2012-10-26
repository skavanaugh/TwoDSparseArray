#include "LinkedList.h"
#include "Node.h"
#include <string>
#include <cassert>

template <typename T>
LinkedList<T>::LinkedList() {
  head=0;
  numElements=0;
}

template <typename T>
LinkedList<T>::LinkedList(Node<T>* h, int nE) {
  head=h;
  numElements=nE;
}

template <typename T>
LinkedList<T>::~LinkedList() {}
    
template <typename T>
Node<T>* LinkedList<T>::getHead() {
  return head;
}

template <typename T>
void LinkedList<T>::setHead(Node<T>* h) {
  head=h;
}

template <typename T>    
int LinkedList<T>::getSize() {
  return numElements;
}

template <typename T>
void LinkedList<T>::setSize(int nE) {
  numElements=nE;
}

template <typename T>
bool LinkedList<T>::isEmpty() {
  return numElements==0;
}
    
//    T getValue();
//    void setValue(T v);
//    int getRow();
//    int getCol();
//    Node<T>* getNextRight();
//    Node<T>* getNextDown();
//    void setNextRight(Node<T>* n);
//    void setNextDown(Node<T>* n);


template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<std::string>;

