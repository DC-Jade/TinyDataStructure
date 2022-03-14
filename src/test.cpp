#include "../include/Vector.h"
#include <iostream>
using mydatastructure::Vector;

void traverse(Vector<int>& vec) {
  int vec_size = vec.getSize();
  for (int i = 0; i < vec_size; ++i) {
    std::cout << vec[i] << "\t";
  }
}
int main() {
  Vector<int> iv(10);
  std::cout << "hello, it's vector" << std::endl;

  // vector<T>::insert
  for (int i = 0; i < 10; ++i) {
    std::cout << iv.insert(i,i) << "\t";
  }
  iv.traverse();
  std::cout << std::endl;
  std::cout << "size before insertion: " << iv.getSize() << std::endl;
  std::cout << "capacity before expanding: " << iv.getCapacity()
            << std::endl;
  iv.insert(1, 1);
  std::cout << "size after insertion: " << iv.getSize() << std::endl;
  std::cout << "capacity after expanding: " << iv.getCapacity()
            << std::endl;
}