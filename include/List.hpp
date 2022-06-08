#ifndef LIST_H
#define LIST_H

#include "../include/ListNode.hpp"
#include <iostream>

namespace mydatastructure {

template <typename T>
class List {
public:
  List() { 
    Init();
    std::cout << "List constructor" << std::endl;
  }
  List(const List<T> &list);
  List(const List<T> &list, Rank r, int n);
  List(ListNodePosi(T) p, int n);
  ~List();
  
  // read_only interface
  Rank Size() const { return _size; }
  bool Empty() const { return _size <= 0; }
  // assert(0 <= r < _size)
  T    operator[](Rank r) const;
  void Tranverse() const;
  ListNodePosi(T) First() const { return _header->_succ; }
  ListNodePosi(T) Last() const { return _trailer->_pred; }
  bool Vaild(ListNodePosi(T) p) const {
    return p && _trailer != p && _header != p;
  }
  int Disordered() const;
  ListNodePosi(T) Find(const T &e, int n, ListNodePosi(T) p) const;
  ListNodePosi(T) Find(const T &e) const {
    return Find(e, _size, _trailer);
  }
  ListNodePosi(T) Search(const T &e, int n, ListNodePosi(T) p) const;
  ListNodePosi(T) Search(const T &e) const {
    return Search(e, _size, _trailer);
  }
  ListNodePosi(T) SelectMax(ListNodePosi(T) p, int n) const;
  ListNodePosi(T) SelectMax() { return SelectMax(_header->_succ, _size); }

  // writable interface
  void            InsertAsFirst(const T &e);
  void            InsertAsLast(const T &e);
  void            InsertAfter(ListNodePosi(T) p, const T &e);
  void            InsertBefore(ListNodePosi(T) p, const T &e);
  T Remove(ListNodePosi(T) p);
  ListNodePosi(T) Merge(List<T> &list) {
    return Merge(First(), _size, list.First(), list._size);
  }
  void Sort(ListNodePosi(T) p, int n);
  void Sort() { Sort(First(), _size); }
  int  Deduplicate();  // remove repeated element in unordered list
  int  Uniquify();     // remove repeated element in ordered list;
  void Reverse();      // list[i] = list[_size - i]

  // protected:
  void Init();
  int  Clear();
  void CopyNodes(ListNodePosi(T), int);
  ListNodePosi(T) Merge(ListNodePosi(T), int, List<T> &list, ListNodePosi(T), int);
  void MergeSort(ListNodePosi(T) , int);
  void MergeSort() {
    MergeSort(First(), _size);
  }
  void SelectionSort(ListNodePosi(T), int);
  void SelectionSort() {
    SelectionSort(First(), _size);
  }
  void InsertionSort(ListNodePosi(T), int);
  void InsertionSort() {
    InsertionSort(First(), _size);
  }

private:
  int _size;
  ListNodePosi(T) _header;   // position before first ListNode
  ListNodePosi(T) _trailer;  // position after last ListNode
  
};

template <typename T>
void List<T>::Init(){
  _size = 0;
  _header = new ListNode<T>;
  _trailer = new ListNode<T>;
  _header->_succ = _trailer;
  _header->_pred = nullptr;
  _trailer->_pred = _header;
  _trailer->_succ = nullptr;
}

template <typename T>
void List<T>::InsertBefore(ListNodePosi(T) p, const T &e) {
  ++_size;
  p->InsertAsPred(e);
}

template <typename T>
void List<T>::InsertAfter(ListNodePosi(T) p, const T &e) {
  ++_size;
  p->InsertAsSucc(e);
}

template <typename T>
T List<T>::Remove(ListNodePosi(T) p) {
  T e = p->_data;
  p->_pred->_succ = p->_succ;
  p->_succ->_pred = p->_pred;
  delete p;
  --_size;
  return e;
}

template <typename T>
void List<T>::InsertAsLast(const T &e) {
  ++_size;
  _trailer->InsertAsPred(e);
}

template <typename T>
void List<T>::InsertAsFirst(const T &e) {
  ++_size;
  _header->InsertAsSucc(e);
}

template <typename T>
void List<T>::CopyNodes(ListNodePosi(T) p, int n) {
  Init();
  while (n--) {
    InsertAsLast(p->_data);
    p = p->_succ;
  }
}

template <typename T>
List<T>::~List() {
  Clear();
  delete _header;
  delete _trailer;
  // std::cout << "\nList deconstructor" << std::endl;
	printf("\nList deconstructor\n");
}

template <typename T>
int List<T>::Clear() {
  int old_size = _size;
  while (0 < _size) {
    Remove(_header->_succ);
  }
  return old_size;
}

template <typename T>
T List<T>::operator[](Rank r) const {
  ListNodePosi(T) p = First();
  while (0 < r--)
    p = p->_succ;
  return p->_data;
}

template <typename T>
void List<T>::Tranverse() const {
  for (ListNodePosi(T) ptr = First(); ptr != _trailer; ptr = ptr->_succ) {
    std::cout << ptr->_data << "\t";
  }
  std::cout << std::endl;
}

template <typename T>
ListNodePosi(T) List<T>::Find(const T &e, int size, ListNodePosi(T) ptr) const {
  while (0 < size--) {
    ptr = ptr->_pred;
    if (ptr->_data == e)
      return ptr;
  }
  return nullptr;
}

template <typename T>
int List<T>::Deduplicate() {
  int old_size = _size;
  ListNodePosi(T) ptr = First();
  for (Rank r = 0; ptr != _trailer; ptr = ptr->_succ){
    if (ListNodePosi(T) q = Find(ptr->_data, r, ptr))
      Remove(q);
    else
      ++r;
  }
  return old_size - _size; 
}

// List<T> is ordered
template <typename T>
int List<T>::Uniquify() {
  if(_size < 2)
    return 0;
  int old_size = _size;
  ListNodePosi(T) ptr = First();
  ListNodePosi(T) ptr_succ = ptr->_succ;
  while (_trailer != ptr_succ) {
    if (ptr->_data != ptr_succ->_data) {
      ptr = ptr_succ;
    }
    else 
      Remove(ptr_succ);
    ptr_succ = ptr->_succ;
  }
  return old_size - _size;
}

template <typename T>
List<T>::List(const List<T> &list) {
  // TODO
}

template <typename T>
ListNodePosi(T) List<T>::Search(const T &e, int n, ListNodePosi(T) p) const {
  while ((0 < n--) && (p = p->_pred)) {
    if (e >= p->_data)
      break;
  }
  return p;
}

// TODO
template <typename T>
void List<T>::SelectionSort(ListNodePosi(T) ptr, int n){
  ListNodePosi(T) head = ptr->_pred;
  ListNodePosi(T) tail = ptr;
  for (Rank i = 0; i < n; ++i)
    tail = tail->_succ;  // sort interval (head, tail)
  while (0 < n--) {
    InsertBefore(tail, Remove(SelectMax(head->_succ, n)));
    tail = tail->_pred;
  }
}

// assert: ptr in [First(), Last()], n in [1,_size]
template <typename T>
ListNodePosi(T) List<T>::SelectMax(ListNodePosi(T) ptr, int n) const {
  ListNodePosi(T) max = ptr;
  while (0 < n--) {
    if ( (ptr = ptr->_succ)->_data >= (max->_data) ) 
      max = ptr;  // stable sort, due to >=
  }
  return max;
}

template <typename T>
void List<T>::InsertionSort(ListNodePosi(T) ptr, int n) {
  for (int i = 0; i < n; ++i) {
    // input sensitive, 0 when ordered, O(n) when reverse
    InsertAfter(Search(ptr->_data, i, ptr), ptr->_data);
    ptr = ptr->_succ;
    Remove(ptr->_pred);
  }
}

template <typename T>
void List<T>::MergeSort(ListNodePosi(T) p, int n) {
  if (n < 2)
    return;
  ListNodePosi(T) q = p;
  int mid = n >> 1;
  for (int i = 0; i < mid; ++i)
    q = q->_succ;
  MergeSort(p, mid);
  MergeSort(q, n - mid);
  p = Merge(p, mid, *this, q, n - mid);
}

// TODO
template <typename T>
ListNodePosi(T) List<T>::Merge(ListNodePosi(T) p, int n,
    List<T> &list, ListNodePosi(T) q, int m) {
  ListNodePosi(T) p_pred = p->_pred;
  while ( (0 < m) && (q != p) ) {
    if ( (0 < n) && (p->_data <= q->_data) ) {
      p = p->_succ;
      --n;
    } else {
      q = q->_succ;
      InsertBefore(p, list.Remove(q->_pred));
      --m;
    }
  }
  return p_pred->_succ;
}  // O(n + m)

}  // namespace mydatastructure

#endif
