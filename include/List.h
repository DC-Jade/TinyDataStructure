#ifndef LIST_H
#define LIST_H

#include "../include/ListNode.h"
#include <iostream>

namespace mydatastructure {

template <typename T>
class List {
public:
  List() { Init(); }
  List(List<T> const &list);
  List(List<T> const &list, Rank r, int n);
  List(ListNodePosi(T) p, int n);
  ~List();
  
  // read_only interface
  Rank Size() const { return _size; }
  bool Empty() const { return _size <= 0; }
  T &operator[](Rank r) const;
  ListNodePosi(T) First() const { return header->_succ; }
  ListNodePosi(T) Last() const { return trailer->_pred; }
  bool Vaild(ListNodePosi(T) p) const {
    return p && trailer != p && header != p;
  }
  int Disordered() const;
  ListNodePosi(T) Find(const T &e, int n, ListNodePosi(T) p) const;
  ListNodePosi(T) Find(const T &e) const {
    return Find(e, _size, trailer);
  }
  ListNodePosi(T) Search(const T &e, int n, ListNodePosi(T) p) const;
  ListNodePosi(T) Search(const T &e) const {
    return Search(e, _size, trailer);
  }
  ListNodePosi(T) SelectMax(ListNodePosi(T) p, int n) const;
  ListNodePosi(T) SelectMax() { return SelectMax(header->_succ, _size); }

  // writable interface
  ListNodePosi(T) InsertAsFirst(const T &e);
  ListNodePosi(T) InsertAsLast(const T &e);
  ListNodePosi(T) InsertAfter(ListNodePosi(T) p, const T &e);
  ListNodePosi(T) InsertBefore(ListNodePosi(T) p, const T &e);
  T Remove(ListNodePosi(T) p);
  void Merge(List<T> &list) {
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
  void Merge(ListNodePosi(T), int, ListNodePosi(T), int);
  void MergeSort(ListNodePosi(T) , int);
  void SelectionSort(ListNodePosi(T), int);
  void InsertionSort(ListNodePosi(T), int);


private:
  int _size;
  ListNodePosi(T) header;   // position before first ListNode
  ListNodePosi(T) trailer;  // position after last ListNode
  
};

template <typename T>
void List<T>::Init(){
  _size = 0;
  header = new ListNode<T>;
  trailer = new ListNode<T>;
  header->_succ = trailer;
  header->_pred = nullptr;
  trailer->_pred = header;
  trailer->_succ = nullptr;
}

template <typename T>
ListNodePosi(T) List<T>::InsertBefore(ListNodePosi(T) p, const T &e) {
  ++_size;
  p->InsertAsPred(e);
}

template <typename T>
ListNodePosi(T) List<T>::InsertAfter(ListNodePosi(T) p, const T &e) {
  ++_size;
  p->InsertAsSucc(e);
}

template <typename T>
T List<T>::Remove(ListNodePosi(T) p) {
  T e = p->data;
  p->_pred->_succ = p->_succ;
  p->_succ->_pred = p->_pred;
  delete p;
  _size--;
  return e;
}

template <typename T>
void List<T>::CopyNodes(ListNodePosi(T) p, int n) {
  Init();
  while (n--) {
    InsertAsLast(p->data);
    p = p->_succ;
  }
}

template <typename T>
List<T>::~List() {
  Clear();
  delete header;
  delete trailer;
}

template <typename T>
int List<T>::Clear() {
  int old_size = _size;
  while (0 < _size) {
    Remove(header->_succ);
  }
  return old_size;
}


}

#endif