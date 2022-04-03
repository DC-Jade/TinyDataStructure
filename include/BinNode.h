#ifndef INCLUDE_BINNODE_H
#define INCLUDE_BINNODE_H

#include <iostream>
namespace mydatastructure {

#define BinNodePosi(T) BinNode<T>*

template <typename T>
class BinNode {
public:
  BinNodePosi(T) _parent;
  BinNodePosi(T) _lc;
  BinNodePosi(T) _rc;
  T _data;
  int _height;

  int Size();
  BinNodePosi(T) InsertAsLc(const T &e);
  BinNodePosi(T) InsertAsRc(const T &e);
  BinNodePosi(T) Succ();
  template <typename VST> void TraverseLevel(VST &);
  template <typename VST> void TraversePre(VST &);
  template <typename VST> void TraverseIn(VST &);
  template <typename VST> void TraversePost(VST &);


}; // class BinNode

}  // namespace mydatastructure

#endif