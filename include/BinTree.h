#ifndef INCLUDE_BINTREE_H
#define INCLUDE_BINTREE_H

#include "../include/BinNode.h"

namespace mydatastructure {

template <typename T>
void Release(T *x) {
  delete x;
}

template <typename T>
class BinTree {
protected:
  int _size;
  BinNodePosi(T) _root;
  virtual int UpdateHeight(BinNodePosi(T) x); // update x's height
  void UpdateHeightAbove(BinNodePosi(T) x);  // update x and ancestors' height
public:
  int  Size() { return _size; }
  bool Empty() { return _size <= 0; };
  BinNodePosi(T) Root() const { return _root; }
  BinNodePosi(T) Insert(BinNodePosi(T) x, const T &e);  // Insert as right child
  BinNodePosi(T) Insert(const T &e, BinNodePosi(T) x);  // Insert as left child
  BinNodePosi(T) Attach(BinTree<T>* &subtree, BinNodePosi(T) x);  // attach as
                                                                  // left tree
  BinNodePosi(T) Attach(BinNodePosi(T) x, BinTree<T>* &subtree);  // attach as
                                                                  // right tree
  int Remove(BinNodePosi(T) x);
  BinTree<T> *Secede(BinNodePosi(T) x);
}; // class BinTree

template <typename T>
inline int Stature(const BinNodePosi(T) ptr) {
  return (ptr->_height) ? ptr->_height : -1;
}


inline int Max(int le, int re) {
  return (le > re) ? le : re;
}

template <typename T>
BinNodePosi(T) BinTree<T>::Insert(BinNodePosi(T) x, const T &e) {
  ++_size;
  x->InsertAsRc(e);
  UpdateHeightAbove(x);
  return x->_rc;
}

template <typename T>
BinNodePosi(T) BinTree<T>::Insert(const T &e, BinNodePosi(T) x) {
  ++_size;
  x->InsertAsLc(e);
  UpdateHeightAbove(x);
  return x->_lc;
}

template <typename T>
BinNodePosi(T) BinTree<T>::Attach(BinNodePosi(T) x, BinTree<T> *&subtree) {
  if (x->_rc = subtree->_root)
    x->_rc->_parent = x;
  _size += subtree->_size;
  UpdateHeightAbove(x);
  subtree->_root = nullptr;
  subtree->_size = 0;
  Release(subtree);
  subtree = nullptr;
  return x;
}

template <typename T>
int BinTree<T>::UpdateHeight(BinNodePosi(T) x) {
  return x->_height = 1 + Max(Stature(x->_lc), Stature(x->_rc));
} 

template <typename T>
void BinTree<T>::UpdateHeightAbove(BinNodePosi(T) x) {
  for (BinNodePosi(T) ptr = x; ptr != nullptr; x = x->_parent) continue;
} 

template <typename T>
int BinTree<T>::Remove(BinNodePosi(T) x) {
  FromParentTo(*x) = nullptr;
  UpdateHeightAbove(x->_parent);
  int n = RemoveAt(x);
  _size -= n;
  return n;
}

template <typename T>
static int RemoveAt(BinNodePosi(T) x) {
  if (!x)
    return 0;
  int n = 1 + RemoveAt(x->_lc) + RemoveAt(x->_rc);
  Release(x);
  return n;
}

template <typename T>
BinTree<T>* BinTree<T>::Secede(BinNodePosi(T) x) {
  FromParentTo(*x) = nullptr;
  UpdateHeightAbove(x->_parent);
  BinTree<T> *subtree = new BinTree<T>;
  subtree->_root = x;
  x->_parent = nullptr;

  _size -= subtree->_size;
  return subtree;
}

} // namespace mydatastructure

#endif