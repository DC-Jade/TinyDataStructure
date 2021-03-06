#ifndef INCLUDE_BINNODE_H
#define INCLUDE_BINNODE_H

#include "../include/Queue.hpp"
#include "../include/Stack.hpp"

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
	_data(T()), _parent(nullptr), _lc(nullptr), _rc(nullptr),
	_height(0), _npl(0), _color(RB_RED) { }

// template <typename T>
// BinNode<T>::BinNode(T e, BinNodePosi(T) parent = nullptr,
//   BinNodePosi(T) lc = nullptr, BinNodePosi(T) rc = nullptr,
//   int height = 0, int npl = 1, RBColor color = RB_RED) : _data(e) { }

template <typename T>
BinNode<T>::BinNode(T data, BinNodePosi(T) parent, BinNodePosi(T) lc,
	BinNodePosi(T) rc, int height, int npl, RBColor color) :
	_data(data), _parent(parent), _lc(lc), _rc(rc), _height(height),
	_npl(npl), _color(color) { } 

template <typename T>
BinNodePosi(T) BinNode<T>::InsertAsLC(const T &e) {
	return _lc = new BinNode<T>(e, this);
} 

template <typename T>
BinNodePosi(T) BinNode<T>::InsertAsRC(const T &e) {
	return _rc = new BinNode<T>(e, this);
} 

template <typename T>
BinNodePosi(T) BinNode<T>::Succ() {
	BinNodePosi(T) successor = this;
	if (_rc) { 
		successor = _rc;
		while (HasLChild(*successor)) { successor = successor->_lc; }
	} else {
		while (IsRChild(*successor)) { successor = successor->_parent; }
		successor = successor->_parent;
	}
	return successor;
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
	switch (rand() % 2) {
		case 1:
			printf("TravelPreIteration\n"); TravelPreIteration(this, visit); break;
		default:
			printf("TravelPreRecursion\n"); TravelPreRecursion(this, visit); break;
	}
	printf("\n");
}

template <typename T> template <typename VST>
void BinNode<T>::TravelIn(VST &visit) {
	switch (rand() % 1 + 3) {
		case 1:
			printf("TravelInItreationOne\n");
			TravelInIterationOne(this, visit); break;
		case 2:
			printf("TravelInItreationTwo\n");
			TravelInIterationTwo(this, visit); break;
		case 3:
			/* no stack S(1) */
			printf("TravelInItreationThree\n");
			TravelInIterationThree(this, visit); break;
		default: 
			printf("TravelInRecursion\n"); TravelInRecursion(this, visit); break;
	}
	printf("\n");
}

template <typename T> template <typename VST>
void BinNode<T>::TravelPost(VST &visit) {
	switch (rand() % 2) {
		case 1: 
			printf("TravelPostIteration\n"); TravelPostIteration(this, visit); break;
		default: 
			printf("TravelPostRecursion\n"); TravelPostRecursion(this, visit); break;
	}
	printf("\n");
}

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
	return rbin_node._parent && rbin_node._parent->_lc == &rbin_node;
}

template <typename T>
bool IsRChild(const BinNode<T> &rbin_node) {
	return rbin_node._parent && rbin_node._parent->_rc == &rbin_node; 
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
static void TravelPreRecursion(BinNodePosi(T) pbin_node, VST &visit) {
	if (!pbin_node) return;
	visit(pbin_node->_data);
	TravelPreRecursion(pbin_node->_lc, visit);
	TravelPreRecursion(pbin_node->_rc, visit);
}

template <typename T, typename VST>
static void VisitAlongLeftBranch(BinNodePosi(T) pbin_node, VST &visit,
	Stack<BinNodePosi(T)> &s_pbn) {
	while (pbin_node) {
		visit(pbin_node->_data);
		s_pbn.Push(pbin_node->_rc);
		pbin_node = pbin_node->_lc;
	}
}

template <typename T, typename VST>
static void TravelPreIteration(BinNodePosi(T) pbin_node, VST &visit) {
	Stack<BinNodePosi(T)> s_pbn;
	while (1) {
		VisitAlongLeftBranch(pbin_node, visit, s_pbn);
		if (s_pbn.Empty()) break;
		pbin_node = s_pbn.Pop();
	}
}

template <typename T, typename VST>
static void TravelInRecursion(BinNodePosi(T) pbin_node, VST &visit) {
	if (!pbin_node) return;
	TravelInRecursion(pbin_node->_lc, visit);
	visit(pbin_node->_data);
	TravelInRecursion(pbin_node->_rc, visit);
}

template <typename T>
// void GoAlongLeftBranch(BinNodePosi(T) pbin_node, Stack<BinNodePosi(T)> &s_pbn) {
static void GoAlongLeftBranch(
	BinNodePosi(T) pbin_node, Stack<BinNodePosi(T)> &s_pbn) {
	while (pbin_node) {
		s_pbn.Push(pbin_node);
		pbin_node = pbin_node->_lc;
	}
}

template <typename T, typename VST>
static void TravelInIterationOne(BinNodePosi(T) pbin_node, VST &visit) {
	Stack<BinNodePosi(T)> s_pbn;
	while (1) {
		GoAlongLeftBranch(pbin_node, s_pbn);
		if (s_pbn.Empty()) break;
		pbin_node = s_pbn.Pop();
		visit(pbin_node->_data);
		pbin_node = pbin_node->_rc;
	}
}

template <typename T, typename VST>
static void TravelInIterationTwo(BinNodePosi(T) pbin_node, VST &visit) {
	Stack<BinNodePosi(T)> s_pbn;
	while (1) {
		if (pbin_node) {
			s_pbn.Push(pbin_node);
			pbin_node = pbin_node->_lc;
		} else if (!s_pbn.Empty()) {
			pbin_node = s_pbn.Pop();
			visit(pbin_node->_data);
			pbin_node = pbin_node->_rc;
		} else  { break; }
	}
}

template <typename T, typename VST>
static void TravelInIterationThree(BinNodePosi(T) pbin_node, VST &visit) {
	bool backtrack = false;
	while (true) {
		if (!backtrack && HasLChild(*pbin_node)) { pbin_node = pbin_node->_lc; }
		else {
			visit(pbin_node->_data);
			if (HasRChild(*pbin_node)) {
				pbin_node = pbin_node->_rc;
				backtrack = false;
			} else {
				if (!(pbin_node = pbin_node->Succ())) break;
				backtrack = true;
			}
		}
	}
}

template <typename T, typename VST>
static void TravelPostRecursion(BinNodePosi(T) pbin_node, VST &visit) {
	if (!pbin_node) return;
	TravelPostRecursion(pbin_node->_lc, visit);
	TravelPostRecursion(pbin_node->_rc, visit);
	visit(pbin_node->_data);
}

template <typename T>
/* HVLL refers to highest visible left leaf */
static void GoToHVLL (Stack<BinNodePosi(T)> &s_pbn) {
	BinNodePosi(T) pbin_node;
	while ((pbin_node = s_pbn.Top())) {
		if (HasLChild(*pbin_node)) {
			if (HasRChild(*pbin_node)) { s_pbn.Push(pbin_node->_rc); }
			s_pbn.Push(pbin_node->_lc);
		} else { s_pbn.Push(pbin_node->_rc); }
	} 
	s_pbn.Pop();
}

template <typename T, typename VST>
static void TravelPostIteration(BinNodePosi(T) pbin_node, VST &visit) {
	Stack<BinNodePosi(T)> s_pbn;
	if (pbin_node) s_pbn.Push(pbin_node);
	while (!s_pbn.Empty()) {
		if (s_pbn.Top() != pbin_node->_parent) GoToHVLL(s_pbn);
		pbin_node = s_pbn.Pop();
		visit(pbin_node->_data);
	}
}



// template <typename T>
// BinNodePosi(T) FromParentTo(const BinNode<T> &rbin_node) {
//   return IsRoot(rbin_node) ? _root :
//     (IsLChild(rbin_node) ? rbin_node._parent->_lc : rbin_node._parent->_rc);
// }

}	/* namespace mydatastructure */

#endif 
