#ifndef INCLUDE_BINTREE_H
#define INCLUDE_BINTREE_H

#include <assert.h>

#include <cstdio>
#include <iostream>

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
class VST; /* class VST */

template <typename T>
class BinTree {
public: 
	/* constructor */
	BinTree();
	~BinTree();

	/* interface */
	virtual int UpdateHeight(BinNode<T> *pbin_node);
	void UpdateHeightAbove(BinNode<T> *pbin_node);
	int Size() const;
	bool Empty() const;
	BinNodePosi(T) Root() const;
	BinNodePosi(T) InsertAsRoot(const T &e);
	/* rbin_node - the position needed to be insert */
	BinNodePosi(T) InsertAsLC(BinNode<T> *pbin_node, const T &e);
	BinNodePosi(T) InsertAsRC(BinNode<T> *pbin_node, const T &e);
	BinNodePosi(T) AttachAsLC(BinNode<T> *pbin_node, BinTree<T>* *pptree);
	BinNodePosi(T) AttachAsRC(BinNode<T> *pbin_node, BinTree<T>* *pptree);
	int Remove(BinNode<T> *pbin_node);	/* remove a subtree */
	BinTree<T>* Secede(BinNode<T> *pbin_node);
	template <typename VST>
	void TravelLevel(VST &visit);
	template <typename VST>
	void TravelPre(VST &visit);
	template <typename VST>
	void TravelIn(VST &visit);
	template <typename VST>
	void TravelPost(VST &visit);
	bool operator<(const BinNode<T> *pbin_node) const;
	bool operator==(const BinNode<T> *pbin_node) const;
	// friend BinNodePosi(T) FromParentTo(BinNode<T> *pbin_node);
	
private:
	int _size;
	BinNodePosi(T) _root;
};	/* class BinTree */

template <typename T>
int BinTree<T>::UpdateHeight(BinNode<T> *pbin_node) {
	return pbin_node->_height =  1 + 
		std::max(Sature(pbin_node->_lc), Sature(pbin_node->_rc));
}

template <typename T>
void BinTree<T>::UpdateHeightAbove(BinNode<T> *pbin_node) {
	while (pbin_node) {
		UpdateHeight(pbin_node);
		pbin_node = pbin_node->_parent;
	}
}

template <typename T>
BinTree<T>::BinTree() : _size(0), _root(nullptr) { }

template <typename T>
BinTree<T>::~BinTree() { if (_size > 0) Remove(_root); printf("~BinTree()\n"); }

template <typename T>
int BinTree<T>::Remove(BinNode<T> *pbin_node) {
	FromParentTo(*pbin_node) = nullptr;
	UpdateHeightAbove(pbin_node->_parent);
	int n = RemoveAt(pbin_node);
	_size -= n;
	return n;
}

/* parameter is pointer to check whether exist but reference cannot */
template <typename T>
int RemoveAt(BinNode<T> *pbin_node) {
	if (!pbin_node) return 0;
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
BinNodePosi(T) BinTree<T>::InsertAsLC(BinNode<T> *pbin_node, const T &e) {
	++_size;
	pbin_node->InsertAsLC(e);
	UpdateHeightAbove(pbin_node);
	return pbin_node->_lc;
}

template <typename T>
BinNodePosi(T) BinTree<T>::InsertAsRC(BinNode<T> *pbin_node, const T &e) {
	++_size;
	pbin_node->InsertAsRC(e);
	UpdateHeightAbove(pbin_node);
	return pbin_node->_rc;
}

template <typename T>
BinNodePosi(T) BinTree<T>::AttachAsLC(BinNode<T> *pbin_node,
	BinTree<T>* *pptree){
	/* pbin_node->_lc == nullptr */
	assert(pbin_node->_lc == nullptr);

	/* change node status */
	pbin_node->_lc = (*pptree)->_root;
	(*pptree)->_root->_parent = pbin_node;
	UpdateHeightAbove(pbin_node);
	_size += (*pptree)->_size;

	/* initialize (*pptree) */
	(*pptree)->_size = 0;
	(*pptree)->_root = nullptr;
	(*pptree) = nullptr;
	return pbin_node;
}

template <typename T>
BinNodePosi(T) BinTree<T>::AttachAsRC(BinNode<T> *pbin_node,
	BinTree<T>* *pptree){
	/* pbin_node->_rc == nullptr */
	assert(pbin_node->_rc == nullptr);

	/* change node status */
	pbin_node->_rc = (*pptree)->_root;
	// pbin_node->_rc->_parent = pbin_node;
	(*pptree)->_root->_parent = pbin_node;
	UpdateHeightAbove(pbin_node);
	_size += (*pptree)->_size;
	
	/* initialize (*pptree) */
	(*pptree)->_root = nullptr;
	(*pptree)->_size = 0;
	// Remove((*pptree)->Root());
	(*pptree) = nullptr;
	return pbin_node;
}

template <typename T> template <typename VST>
void BinTree<T>::TravelLevel(VST &visit) {
	if (_root) { _root->TravelLevel(visit); }
}

template <typename T> template <typename VST>
void BinTree<T>::TravelPre(VST &visit) {
	if (_root) { _root->TravelPre(visit); }
}

template <typename T> template <typename VST>
void BinTree<T>::TravelIn(VST &visit) {
	if (_root) { _root->TravelIn(visit); }
}

template <typename T> template <typename VST>
void BinTree<T>::TravelPost(VST &visit) {
	if (_root) { _root->TravelPost(visit); }
}

template <typename T>
class VST {
public:
	void operator()(T &e) { std::cout << e << '\t'; }
};	/* class VST */

/* non function member  */

};	/* namespace mydatastructure */

#endif 



