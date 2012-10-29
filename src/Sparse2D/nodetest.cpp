#include "Node.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main() {
  Node<int>* intNode = new Node<int>(7,3,3);
  cout << intNode->getValue() << endl;
  Node<double>* dNode = new Node<double>(3.14159,4,0);
  cout << dNode->getValue() << endl;
  Node<std::string> sNode = Node<std::string>("Brass Monkey",1,0);
  cout << sNode.getValue() << endl;

  delete intNode;
  delete dNode;
//  delete &sNode;

  return 0;
}
