#include <iostream>
#include "../include/Vector.h"
#include "../include/List.h"
#include "../include/Stack.h"
#include "../include/Queue.h"

using mydatastructure::Vector;
using mydatastructure::List;
using mydatastructure::ListNode;
using mydatastructure::Stack;
using mydatastructure::Queue;

void Tranverse(Vector<int>& vec) {
  int vec_size = vec.Size();
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

  // Vector<T>::Insert
  for (int i = 0; i < 10; ++i) {
    std::cout << iv.Insert(i,i) << "\t";
  }
  for (int i = 0; i < 10; ++i) {
    std::cout << iv_ordered.Insert(i,i) << "\t";
  }
  iv.Tranverse();
  std::cout << std::endl;
  std::cout << "size before Insertion: " << iv.GetSize() << std::endl;
  std::cout << "capacity before expanding: " << iv.GetCapacity()
            << std::endl;
  iv.Insert(1, 10);
  std::cout << "size after Insertion: " << iv.GetSize() << std::endl;
  std::cout << "capacity after expanding: " << iv.GetCapacity()
            << std::endl;
  iv.Tranverse();
  
  // Vector<T>::Remove
  iv.Remove(0, 1);
  iv.Tranverse();
  
  // Vector<T>::Find, unordered
  iv.Insert(1, 1);
  iv.Tranverse();
  std::cout << "Find(1, 0, 2): " << iv.Find(1, 0, 2) << std::endl;
  std::cout << "Find(1): " << iv.Find(1) << std::endl;
  std::cout << "Find(no existence): " << iv.Find(11) << std::endl;

  // Vector<T>::Deduplicate
  iv.Deduplicate();
  std::cout << "after deduplicating "; 
  iv.Tranverse();

  // Vector<T>::Uniquify
  iv.Insert(1, 10);
  iv.Tranverse();
  std::cout << "after Uniquify "; 
  iv.Uniquify();
  iv.Tranverse();

  // Vector<T>::Search
  iv_ordered.Tranverse();
  std::cout << "Search(2): " << iv_ordered.Search(2) << std::endl;

  // swap
  int iv0 = iv[0];
  int iv9 = iv[10];
  swap(iv[0], iv[10]);
  iv0 = iv[0];
  iv9 = iv[10];
  
  // BubbleSort
  //iv.Tranverse();
  std::cout << "iv.size: " << iv.GetSize() << std::endl; 
  std::cout << "unSorted: ";
  iv.Tranverse();
  iv.BubbleSort(0, 10);
  std::cout << "Sorted: ";
  iv.Tranverse();

  // MergeSort
  iv.Insert(5, 8);
  std::cout << "iv.size: " << iv.GetSize() << std::endl; 
  std::cout << "unSorted: ";
  iv.Tranverse();
  iv.MergeSort(3,7);
  iv.MergeSort();
  std::cout << "Sorted: ";
  iv.Tranverse();
  */

  /*
  @ List<T> test
  */
  /*
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
  std::cout << "list.Find(2): " << list.Find(2)->_data << std::endl;
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
  list.InsertAfter(list.Find(2), list.Find(2)->_data);
  std::cout << "Before Uniquify: " << std::endl;
  list.Tranverse();
  std::cout << "After Uniquify: " << std::endl;
  list.Uniquify();
  list.Tranverse();
  //ListNodePosi(int) tmp = list.Search(2);
  // List<T>::Search
  std::cout << list.Search(2)->_data << std::endl;
  // List<T>::SelectionSort 
  list.InsertAsFirst(10);
  list.InsertAsFirst(5);
  list.Tranverse();
  list.SelectionSort();
  // List<T>::InsertionSort
  std::cout << "Before InsertionSort: " << std::endl;
  list.InsertAsFirst(10);
  list.InsertAsFirst(5);
  list.Tranverse();
  std::cout << "After InsertionSort: " << std::endl;
  list.InsertionSort();
  list.Tranverse();
  // List<T>::MergeSort
  std::cout << "Before MergeSort: " << std::endl;
  list.InsertAsFirst(10);
  list.InsertAsFirst(5);
  list.Tranverse();
  std::cout << "After MergeSort: " << std::endl;
  list.MergeSort();
  list.Tranverse();
  */

  /*
  @ Stack<T>
  */
  /*
  Stack<int> stack;
  // Stack<T>::Push, Pop, Top
  stack.Push(2);
  std::cout << stack.Pop() << std::endl;
  stack.Push(2);
  std::cout << stack.Top() << std::endl;
  std::cout << stack.Size() << std::endl;
  std::cout << (stack.Empty() ? "Empty" : "Not empty") << std::endl;
  */

  /*
  @ Queue<T>
  */
  Queue<int> queue;
  queue.Enqueue(2);
  queue.Enqueue(1);
  std::cout << queue.Front() << std::endl;
  std::cout << queue.Dequeue() << std::endl;
  std::cout << queue.Size() << std::endl;
}