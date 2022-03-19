#include <iostream>
#include "../include/Vector.h"

using mydatastructure::Vector;

void traverse(Vector<int>& vec) {
  int vec_size = vec.getSize();
  for (int i = 0; i < vec_size; ++i) {
    std::cout << vec[i] << "\t";
  }
}

int main() {
  /* 
  @ Vector<T>
  */
  Vector<int> iv(10);
  Vector<int> iv_ordered(10);
  //Vector<int> iv1(iv);
  std::cout << "hello, it's vector" << std::endl;

  // Vector<T>::insert
  for (int i = 0; i < 10; ++i) {
    std::cout << iv.insert(i,i) << "\t";
  }
  for (int i = 0; i < 10; ++i) {
    std::cout << iv_ordered.insert(i,i) << "\t";
  }
  iv.traverse();
  std::cout << std::endl;
  std::cout << "size before insertion: " << iv.getSize() << std::endl;
  std::cout << "capacity before expanding: " << iv.getCapacity()
            << std::endl;
  iv.insert(1, 10);
  std::cout << "size after insertion: " << iv.getSize() << std::endl;
  std::cout << "capacity after expanding: " << iv.getCapacity()
            << std::endl;
  iv.traverse();
  
  // Vector<T>::remove
  iv.remove(0, 1);
  iv.traverse();
  
  // Vector<T>::find, unordered
  iv.insert(1, 1);
  iv.traverse();
  std::cout << "find(1, 0, 2): " << iv.find(1, 0, 2) << std::endl;
  std::cout << "find(1): " << iv.find(1) << std::endl;
  std::cout << "find(no existence): " << iv.find(11) << std::endl;

  // Vector<T>::deduplicate
  iv.deduplicate();
  std::cout << "after deduplicating "; 
  iv.traverse();

  // Vector<T>::uniquify
  iv.insert(1, 10);
  iv.traverse();
  std::cout << "after uniquify "; 
  iv.uniquify();
  iv.traverse();

  // Vector<T>::search
  iv_ordered.traverse();
  std::cout << "search(2): " << iv_ordered.search(2) << std::endl;

  // swap
  int iv0 = iv[0];
  int iv9 = iv[10];
  swap(iv[0], iv[10]);
  iv0 = iv[0];
  iv9 = iv[10];
  
  // bubbleSort
  //iv.traverse();
  std::cout << "iv.size: " << iv.getSize() << std::endl; 
  std::cout << "unsorted: ";
  iv.traverse();
  iv.bubbleSort(0, 10);
  std::cout << "sorted: ";
  iv.traverse();

  // mergeSort
  iv.insert(5, 8);
  std::cout << "iv.size: " << iv.getSize() << std::endl; 
  std::cout << "unsorted: ";
  iv.traverse();
  iv.mergeSort(0, 11);
  std::cout << "sorted: ";
  iv.traverse();

}