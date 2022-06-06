#ifndef INCLUDE_BINTREE_H
#define INCLUDE_BINTREE_H

#include "../include/BinNode.hpp"

/* non member function */
// template <typename T>
// BinNodePosi(T) FromParentTo(BinNode<T> &rbin_node) {
//   return IsRoot(rbin_node) ? _root :
//     (IsLChild(rbin_node) ? rbin_node._parent->_rc : rbin_node._parent->_rc)
// }
#define FromParentTo(rbin_node) \
	(IsRoot(rbin_node) ? _root : \
	(IsLChild(rbin_node) ? (rbin_node)._parent->_lc : (rbin_node)._parent->_rc))

namespace mydatastructure {

template <typename T>
class BinTree {
public: 
	/* constructor */
	BinTree();
	~BinTree();

	/* interface */
	virtual int UpdateHeight(BinNode<T> &rbin_node);
	void UpdateHeightAbove(BinNode<T> &rbin_node);
	int Size() const;
	bool Empty() const;
	BinNodePosi(T) Root() const;
	BinNodePosi(T) InsertAsRoot(const T &e);
	/* rbin_node - the position needed to be insert */
	BinNodePosi(T) InsertAsLC(BinNode<T> &rbin_node, const T &e);
	BinNodePosi(T) InsertAsRC(BinNode<T> &rbin_node, const T &e);
	BinNodePosi(T) AttachAsLC(BinNode<T> &rbin_node, BinTree<T>* &tree);
	BinNodePosi(T) AttachAsRC(BinNode<T> &rbin_node, BinTree<T>* &tree);
	int Remove(BinNode<T> *pbin_node);	/* remove a subtree */
	BinTree<T>* Secede(BinNode<T> &rbin_node);
	template <typename VST>
	void TravelLevel(VST &visit);
	template <typename VST>
	void TravelPre(VST &visit);
	template <typename VST>
	void TravelIn(VST &visit);
	template <typename VST>
	void TravelPost(VST &visit);
	bool operator<(const BinNode<T> &rbin_node) const;
	bool operator==(const BinNode<T> &rbin_node) const;

	// friend BinNodePosi(T) FromParentTo(BinNode<T> &rbin_node);
	
protected:
	int _size;
	BinNodePosi(T) _root;
};	/* class BinTree */

template <typename T>
BinTree<T>::BinTree() : _size(0), _root(nullptr) { }

template <typename T>
BinTree<T>::~BinTree() { if (_size > 0) Remove(_root); }

template <typename T>
int BinTree<T>::Remove(BinNode<T> *pbin_node) {
	FromParentTo(*pbin_node) = nullptr;
	UpdateHeightAbove(*(pbin_node->_parent));
	int n = RemoveAt(pbin_node);
	_size -= n;
	return n;
}

/* parameter is pointer to check whether exist but reference cannot */
template <typename T>
int RemoveAt(BinNode<T> *pbin_node) {
	if (pbin_node) return 0;
	int n = 1 + RemoveAt(pbin_node->_lc) + RemoveAt(pbin_node->_rc);
	delete pbin_node;
	return n;
}

template <typename T>
int BinTree<T>::Size() const { return _size; }

template <typename T>
bool BinTree<T>::Empty() const { return (bool) !_root; }

template <typename T>
BinNodePosi(T) BinTree<T>::Root() const { return _root; }

template <typename T>
BinNodePosi(T) BinTree<T>::InsertAsRoot(const T &e) {
	_size = 1;
	return _root = new BinNode<T>(e);
}

template <typename T>
BinNodePosi(T) BinTree<T>::InsertAsLC(BinNode<T> &rbin_node, const T &e) {
	++_size;
	rbin_node.InsertAsLC(e);
	UpdateHeightAbove(rbin_node);
	return rbin_node._lc;
}

template <typename T>
BinNodePosi(T) BinTree<T>::InsertAsRC(BinNode<T> &rbin_node, const T &e) {
	++_size;
	rbin_node.InsertAsRC(e);
	UpdateHeightAbove(rbin_node);
	return rbin_node._rc;
}
	
};	/* namespace mydatastructure */

#endif 



