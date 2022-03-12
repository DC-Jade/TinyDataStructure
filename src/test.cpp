#include "../include/Vector.h"
#include <iostream>
using mydatasturcture::Vector;

int main() {
  Vector<int> iv;
  std::cout << "hello, it's vector" << std::endl;
  for (int i = 0; i < 10; ++i) {
    std::cout << iv[i] << "\t";
  }
  std::cout << std::endl;
  iv.traverse();
  std::cout << std::endl;
}