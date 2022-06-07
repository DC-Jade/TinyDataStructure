#ifndef INCLUDE_BINNODE_H
#define INCLUDE_BINNODE_H

#include "../include/Queue.hpp"

namespace mydatastructure {
#define BinNodePosi(T) BinNode<T>*

typedef enum { RB_RED, RB_BLACK } RBColor;

template <typename T>
class BinNode {
public:
	/* constructor */
	BinNode();
	BinNode(T e, BinNodePosi(T) parent = nullptr, BinNodePosi(T) lc = nullptr,
		BinNodePosi(T) rc = nullptr, int height = 0, int npl = 1,
		RBColor color = RB_RED);

	/* interface */
	int Size();	/* the number of whole child nodes  */
	BinNodePosi(T) InsertAsLC(const T &e);
	BinNodePosi(T) InsertAsRC(const T &e);
	BinNodePosi(T) Succ();
	template <typename VST>
	void TravelLevel(VST &visit);
	template <typename VST>
	void TravelPre(VST &visit);
	template <typename VST>
	void TravelIn(VST &visit);
	template <typename VST>
	void TravelPost(VST &visit);

	bool operator==(const BinNode &bin_node);
	bool operator<(const BinNode &bin_node);
	bool operator>(const BinNode &bin_node);

	/* data member */
	T _data;
	BinNodePosi(T) _parent; BinNodePosi(T) _lc; BinNodePosi(T) _rc;
	int _height;
	int _npl;	/* null path length, similar to _height */
	RBColor _color; 

};	/* class BinNode<T> */

/* function member */
template <typename T>
BinNode<T>::BinNode() :
	_parent(nullptr), _lc(nullptr), _rc(nullptr),
	_height(0), _npl(0), _color(RB_RED) { }

// template <typename T>
// BinNode<T>::BinNode(T e, BinNodePosi(T) parent = nullptr,
//   BinNodePosi(T) lc = nullptr, BinNodePosi(T) rc = nullptr,
//   int height = 0, int npl = 1, RBColor color = RB_RED) : _data(e) { }

template <typename T>
BinNode<T>::BinNode(T e, BinNodePosi(T) parent, BinNodePosi(T) lc,
	BinNodePosi(T) rc, int height, int npl, RBColor color) :
	_data(e), _parent(parent), _lc(lc), _rc(rc), _height(height),
	_npl(npl), _color(color) { } 

template <typename T>
BinNodePosi(T) BinNode<T>::InsertAsLC(const T &e) {
	return _lc = new BinNode<T>(e, this);
} 

template <typename T>
BinNodePosi(T) BinNode<T>::InsertAsRC(const T &e) {
	return _rc = new BinNode<T>(e, this);
} 

template <typename T> template <typename VST>
void BinNode<T>::TravelLevel(VST &visit) {
	Queue<BinNodePosi(T)> q_pbn;
	q_pbn.Enqueue(this);
	BinNodePosi(T) pbn;
	while (!q_pbn.Empty()) {
		pbn = q_pbn.Dequeue();
		visit(pbn->_data);
		if (HasLChild(*pbn)) { q_pbn.Enqueue(pbn->_lc); }
		if (HasRChild(*pbn)) { q_pbn.Enqueue(pbn->_rc); }
	}
}

template <typename T> template <typename VST>
void BinNode<T>::TravelPre(VST &visit) {
	switch (rand() % 1) {
		default:
			printf("TravelPreRecursion\n"); TravelPreRecursion(this, visit); break;
	}
	printf("\n");
}

template <typename T> template <typename VST>
void BinNode<T>::TravelPost(VST &visit) {
	switch (rand() % 1) {
		default: 
			printf("TravelPostRecursion\n"); TravelPostRecursion(this, visit); break;
	}
	printf("\n");
}

template <typename T> template <typename VST>
void BinNode<T>::TravelIn(VST &visit) {
	switch (rand() % 1) {
		default: 
			printf("TravelInRecursion\n"); TravelInRecursion(this, visit); break;
	}
	printf("\n");
}

// template <typename T, typename VST>
// void BinNode<T>::TravelIn(VST &visit) {
	// switch(rand() % 1 + 1) {
		// case 1: TravelInIterationOne(this, visit); break;
		// case 2: TravelInIterationTwo(this, visit); break;
		// case 3: TravelInIterationThree(this, visit); break;
		// case 4: TravelInIterationFour(this, visit); break;
		// default: TravelInRecusion(this, visit); break;
	// }
// }

// template <typename T>
// int BinNode<T>::Size() {}

/* non function member */
template <typename T>
inline int Sature(const BinNodePosi(T) p) {
	return (p) ? p->_height : -1;
}

template <typename T> 
bool IsRoot(const BinNode<T> &rbin_node) {
	/* rbin_node reference to a bin_node */
	return !(rbin_node._parent);
}

template <typename T>
bool IsLChild(const BinNode<T> &rbin_node) {
	return rbin_node._parent && rbin_node._parent->_lc;
}

template <typename T>
bool IsRChild(const BinNode<T> &rbin_node) {
	return rbin_node._parent && rbin_node._parent->_rc;
}

template <typename T>
bool IsChild(const BinNode<T> &rbin_node) {
	return IsLChild(rbin_node) || IsRChild(rbin_node);
}

template <typename T>
bool HasLChild(const BinNode<T> &rbin_node) {
	return rbin_node._lc;
}

template <typename T>
bool HasRChild(const BinNode<T> &rbin_node) {
	return rbin_node._rc;
}

template <typename T>
bool HasChild(const BinNode<T> &rbin_node) {
	return HasLChild(rbin_node) || HasRChild(rbin_node);
}

template <typename T>
bool HasBothChild(const BinNode<T> &rbin_node) {
	return HasLChild(rbin_node) && HasRChild(rbin_node);
}

template <typename T>
bool IsLeaf(const BinNode<T> &rbin_node) {
	/* cannot use height == 0, due to InsertAsLC do not update height */
	// return (bool) !(rbin_node._height);
	/* another method */
	return !HasChild(rbin_node);
}

template <typename T>
BinNodePosi(T) Sibling(const BinNode<T> &rbin_node) {
	return IsLChild(rbin_node) ? rbin_node._parent->_rc : rbin_node._parent->_lc;
}

template <typename T>
BinNodePosi(T) Uncle(const BinNode<T> &rbin_node) {
	Sibling(*(rbin_node._parent));
}

template <typename T, typename VST>
void TravelPreRecursion(BinNodePosi(T) pbin_node, VST &visit) {
	if (!pbin_node) return;
	visit(pbin_node->_data);
	TravelPreRecursion(pbin_node->_lc, visit);
	TravelPreRecursion(pbin_node->_rc, visit);
}

template <typename T, typename VST>
void TravelInRecursion(BinNodePosi(T) pbin_node, VST &visit) {
	if (!pbin_node) return;
	TravelInRecursion(pbin_node->_lc, visit);
	visit(pbin_node->_data);
	TravelInRecursion(pbin_node->_rc, visit);
}

template <typename T, typename VST>
void TravelPostRecursion(BinNodePosi(T) pbin_node, VST &visit) {
	if (!pbin_node) return;
	TravelPostRecursion(pbin_node->_lc, visit);
	TravelPostRecursion(pbin_node->_rc, visit);
	visit(pbin_node->_data);
}

// template <typename T>
// BinNodePosi(T) FromParentTo(const BinNode<T> &rbin_node) {
//   return IsRoot(rbin_node) ? _root :
//     (IsLChild(rbin_node) ? rbin_node._parent->_lc : rbin_node._parent->_rc);
// }

}	/* namespace mydatastructure */

#endif 
