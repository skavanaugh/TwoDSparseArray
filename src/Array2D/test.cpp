#include "TwoDArray.h"
#include <iostream>

int main() {
  TwoDArray<int> *arr = new TwoDArray<int>(5,2,989);
  arr->print();
  delete arr;


  return 0;
}
