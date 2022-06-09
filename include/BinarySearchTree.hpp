#ifndef INCLUDE_BINARYSEARCHTREE_H
#define INCLUDE_BINARYSEARCHTREE_H

#include "../include/BinTree.hpp"

namespace mydatastructure {

template <typename T>
class BST : public BinTree<T> {
public:
	/* interface */
	virtual BinNodePosi(T) &Search(const T &key);
	virtual BinNodePosi(T) Insert(const T &key);
	virtual bool Remove(const T &value);
	BinNodePosi(T) Connect34(/* three nodes and four subtrees */
		BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
		BinNodePosi(T), BinNodePosi(T), BinNodePosi(T));
	BinNodePosi(T) RotateAt(BinNodePosi(T) pbin_node);

protected:
	BinNodePosi(T) _hot;	/* parent of captured node */
};	/* class BST<T> */

template <typename T>
BinNodePosi(T) &SearchIn(BinNodePosi(T) &pbin_node, const T &key,
	BinNodePosi(T) &hot) {
	if (!pbin_node || key == pbin_node->_data) return pbin_node;
	hot = pbin_node;
	pbin_node = (key < pbin_node->_data) ? pbin_node->_lc : pbin_node->_rc;
	return SearchIn(pbin_node, key, hot);
} 

template <typename T>
BinNodePosi(T) &BST<T>::Search(const T &key) {
	return SearchIn(BST::_root, key, _hot = nullptr);
}

/* BST:: scope acess member */
template <typename T>
BinNodePosi(T) BST<T>::Insert(const T &key) {
	BinNodePosi(T) &pbin_node = Search(key);
	if (pbin_node) return pbin_node;
	pbin_node = new BinNode<T>(key, _hot);
	++BST::_size;
	BST::UpdateHeightAbove(pbin_node);
	return pbin_node;
}

template <typename T>
bool BST<T>::Remove(const T &e) {
	BinNodePosi(T) &rpbin_node = Search(e);
	if (!rpbin_node) return false;
	// RemoveAt(rpbin_node, _hot);
	RemoveAt(rpbin_node);
	BST::_hot = nullptr;
	--BST::_size;
	BST::UpdateHeightAbove(_hot);
	return true;
}

}	/* namespace mydatastructure */

#endif
