#ifndef INCLUDE_SKIPLIST_H
#define INCLUDE_SKIPLIST_H

#include "../include/List.hpp"
#include "../include/Dictionary.hpp"
#include "../include/Entry.hpp"
#include "../include/QuadList.hpp"

namespace mydatastructure {

template <typename K, typename V>
class SkipList : public Dictionary<K, V>, public List<QuadList<Entry<K, V>>*> {
protected:
	bool SkipSearch(ListNode<QuadList<Entry<K, V>>*>* &qlist,
		QuadListNode<Entry<K, V>>* &p, K &k);

public:
	int		_size() const { return Empty() ? 0 : Last()->_data->Size(); }
	int		Level() { return List::Size(); }
	bool	Put(K, V);
	V			*Get(K k);
	bool	Remove(K k);
};	/* class SkipList */


}  /* namespace mydatastructure */

#endif
