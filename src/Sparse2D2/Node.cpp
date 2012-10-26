#include "Node.h"
#include <string>
#include <cassert>

template <typename T>
Node<T>::Node(T v, int r, int c) {
  assert(r>=0 && c>=0);
  value=v;
  row=r;
  col=c;
  nextRight=0;
  nextDown=0;
}

template <typename T>
Node<T>::~Node() {}

template <typename T>
T Node<T>::getValue() {
  return value;
}

template <typename T>
void Node<T>::setValue(T v) {
  value=v;
}

template <typename T>
int Node<T>::getRow() {
  return row;
}

template <typename T>
int Node<T>::getCol() {
  return col;
}

template <typename T>
Node<T>* Node<T>::getNextRight() {
  return nextRight;
}

template <typename T>
Node<T>* Node<T>::getNextDown() {
  return nextDown;
}

template <typename T>
void Node<T>::setNextRight(Node<T>* n) {
  nextRight=n;
}

template <typename T>
void Node<T>::setNextDown(Node<T>* n) {
  nextDown=n;
}

template class Node<int>;
template class Node<double>;
template class Node<std::string>;

