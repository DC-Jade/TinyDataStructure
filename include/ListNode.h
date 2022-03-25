#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <iostream>

namespace mydatastructure {

typedef int Rank;
#define ListNodePosi(T) ListNode<T> *

template <typename T>
class ListNode{
public:
  T _data;
  ListNodePosi(T) _pred;
  ListNodePosi(T) _succ;
  ListNode(){};
  ListNode(T e, ListNodePosi(T) p = nullptr, ListNodePosi(T) s = nullptr)
      : _data(e), _pred(p), _succ(s) {}

  // interface
  ListNodePosi(T) InsertAsPred(const T &e);
  ListNodePosi(T) InsertAsSucc(const T &e);

};

template <typename T>
ListNodePosi(T) ListNode<T>::InsertAsPred(const T &e) {
  ListNodePosi(T) list_node_position = new ListNode(e, _pred, this);
  _pred->_succ = list_node_position;
  _pred = list_node_position;
  return list_node_position;
}

template <typename T>
ListNodePosi(T) ListNode<T>::InsertAsSucc(const T &e) {
  ListNodePosi(T) list_node_position = new ListNode(e, this, _succ);
  _succ->_pred = list_node_position;
  _succ = list_node_position;
  return list_node_position;
}
}



#endif