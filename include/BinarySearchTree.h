#include "../include/BinTree.h"

namespace mydatastructure {

template <typename T>
class BST : public BinTree<T> {
protected:
  BinNodePosi(T) _hot;
  BinNodePosi(T) Connect34(
    BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
    BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T) 
  );
  BinNodePosi(T) RotateAt(BinNodePosi(T) ptr);
public:
  virtual BinNodePosi(T) &Search(const T &e);
  virtual BinNodePosi(T) Insert(const T &e);
  virtual bool Remove(const T &e);
}; // class BinarySearchTree

//TODO: bulid binary search tree
/*
template <typename T>
void BSTBulid(BinTree<T> &bst, int n, const T &e) {
  bst.InsertAsRoot(e);
  T le_init = e - 1;
  T re_init = e + 1;
  T le, re;
  BinNodePosi(T) ptr = bst.Root();
  //int h = n >> 1;
  while (0 < n) {
    le = ptr->_data - 1;
    re = ptr->_data + 1;
    //if ((i % 2 == 0)  && le <= ptr->_data) {
    bst.Insert(le, ptr);
    --n;
    bst.Insert(ptr, re);
    --n;
    ptr = ptr->_lc;
    //}

  }
}
*/

template <typename T>
BinNodePosi(T) &SearchIn(BinNodePosi(T) &v, const T &e, BinNodePosi(T) &hot){
  if (!v || (e == v->_data))
    return v;
  hot = v;  // hot = v->_parent
  return SearchIn(((e < v->_data) ? v->_lc : v->_rc), e, hot);
}

template <typename T>
BinNodePosi(T) &BST<T>::Search(const T &e) {
  return SearchIn(this->_root, e, _hot = nullptr);
}

template <typename T>
BinNodePosi(T) BST<T>::Insert(const T &e) {
  BinNodePosi(T) &r = Search(e);
  if (r)
    return r;
  r = new BinNode<T>(e, _hot);
  ++_size;
  UpdateHeightAbove(r);
  return r;
}

}  // namespace mydatastructure