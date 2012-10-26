#ifndef __NODE_H__
#define __NODE_H__

template <typename T>
class Node {
  private:
    T value;
    int row;
    int col;
    Node<T>* nextRight;
    Node<T>* nextDown;

  public:
    Node<T>(T v, int r, int c);
    ~Node<T>();
    T getValue();
    void setValue(T v);
    int getRow();
    int getCol();
    Node<T>* getNextRight();
    Node<T>* getNextDown();
    void setNextRight(Node<T>* n);
    void setNextDown(Node<T>* n);
};
#endif

