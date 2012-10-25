#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {
  private:
    T value;
    Node<T>* nextRow;
    Node<T>* nextCol;

  public:
    Node<T>(T v);
    ~Node<T>();
    T getValue();
    Node<T>* getNextRow();
    Node<T>* getNextCol();
    void setNextRow(Node<T> &n);
    void setNextCol(Node<T> &n);
};
#endif

