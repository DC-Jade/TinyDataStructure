#include <iostream>
#include "../include/Vector.h"
#include "../include/List.h"

using mydatastructure::Vector;
using mydatastructure::List;
using mydatastructure::ListNode;

void traverse(Vector<int>& vec) {
  int vec_size = vec.getSize();
  for (int i = 0; i < vec_size; ++i) {
    std::cout << vec[i] << "\t";
  }
}

int main() {
  /* 
  @ Vector<T> test
  */
  /*
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
  iv.mergeSort(3,7);
  iv.mergeSort();
  std::cout << "sorted: ";
  iv.traverse();
  */


  /*
  @ List<T> test
  */
  // List<T>::init
  List<int> list;
  // List<T>::InsertAfter
  for (int i = 0, size = 10; i < size; ++i) {
    list.InsertAfter(list.Last(), i % 5);
  }
  // List<T>::Tranverse
  list.Tranverse();
  // List<T>::operator[]
  std::cout << list[1] << std::endl;
  // List<T>::Find
  std::cout << "list.Find(2): " << list.Find(2)->data << std::endl;
  // List<T>::Remove
  std::cout << list.Remove(list.Find(0));
  // List<T>::Deduplicate
  list.InsertAsFirst(10);
  std::cout << "Before Deduplication: " << std::endl;
  list.Tranverse();
  list.Deduplicate();
  std::cout << "After Deduplication: " << std::endl;
  list.Tranverse();
  // List<T>::Clear
  std::cout << "Clear list: " << list.Clear() << std::endl;
  // List<T>::Uniquify
  for (int i = 0, size = 4; i < size; ++i) {
    list.InsertAfter(list.Last(), i % 5);
  }
  list.InsertAfter(list.Find(2), list.Find(2)->data);
  std::cout << "Before Uniquify: " << std::endl;
  list.Tranverse();
  std::cout << "After Uniquify: " << std::endl;
  list.Uniquify();
  list.Tranverse();
  //ListNodePosi(int) tmp = list.Search(2);
  // List<T>::Search
  std::cout << list.Search(2)->data << std::endl;
  list.InsertAsFirst(10);
  list.InsertAsFirst(5);
  list.Tranverse();
  //TODO  List<T>::SelectionSort 
  list.SelectionSort();
  list.Tranverse();
  // NEXT
}