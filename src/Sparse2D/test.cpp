#include "TwoDArray.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

int main() {
  TwoDArray<int> *arr = new TwoDArray<int>(7,5,14);
  arr->insert(3,2,999);
  arr->insert(6,4,864);
  arr->print();
  arr->remove(3,2);
  arr->print();
  delete arr;

  TwoDArray<double> *arr2= new TwoDArray<double>(5,3,3.1415);
  arr2->insert(0,0,2.1);
  arr2->print();
  delete arr2;

  TwoDArray<std::string> *arr3=new TwoDArray<std::string>(4,6,"hi");
  arr3->insert(0,2,"moo");
  arr3->print();
  delete arr3;

  return 0;
}
