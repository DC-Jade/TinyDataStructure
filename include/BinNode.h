#ifndef INCLUDE_BINNODE_H
#define INCLUDE_BINNODE_H

#include <iostream>
namespace mydatastructure {

#define BinNodePosi(T) BinNode<T>*

template <typename T>
class BinNode {
public:
  T _data;
  BinNodePosi(T) _parent;
  BinNodePosi(T) _lc;
  BinNodePosi(T) _rc;
  int _height;
  BinNode() : _parent(nullptr), _lc(nullptr), _rc(nullptr), _height(0) {
    std::cout << "BinNode default constructor" << std::endl;
  }
  BinNode(T e, BinNodePosi(T) parent = nullptr, BinNodePosi(T) lc = nullptr,
          BinNodePosi(T) rc = nullptr, int height = 0)
          : _data(e), _parent(parent), _lc(lc), _rc(rc), _height(height) {
    std::cout << "BinNode constructor" << std::endl;
  }
  //~BinNode() {
  //  delete[] _parent;
  //  delete[] _lc;
  //  delete[] _rc;
  //  std::cout << "BinNode deconstructor" << std::endl;
  //}
  int Size();
  BinNodePosi(T) InsertAsLc(const T &e);
  BinNodePosi(T) InsertAsRc(const T &e);
  BinNodePosi(T) Succ();
  template <typename VST> void TraverseLevel(VST &);
  template <typename VST> void TraversePre(VST &);
  template <typename VST> void TraverseIn(VST &);
  template <typename VST> void TraversePost(VST &);


}; // class BinNode

template <typename T>
BinNodePosi(T) BinNode<T>::InsertAsLc(const T &e) {
  return _lc = new BinNode(e, this);
}

template <typename T>
BinNodePosi(T) BinNode<T>::InsertAsRc(const T &e) {
  return _rc = new BinNode(e, this);
}

template <typename T>
int BinNode<T>::Size() {
  int s = 1;
  if (_lc)
    s += _lc->Size();
  if (_rc)
    s += _rc->Size();
  return s;
}
}  // namespace mydatastructure

#endif