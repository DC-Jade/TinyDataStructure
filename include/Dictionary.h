#ifndef INCLUDE_DICTIONARY_H
#define INCLUDE_DICTIONARY_H

namespace mydatastructure {
	
template <typename K, typename V> struct Dictionary {
	virtual int Size() const	= 0;	/* get number of entry	 */
	virtual bool Put(K, V)		= 0;	/* insert entry */
	virtual V *Get(K k)				= 0;	/* get entry */
	virtual bool Remove(K, k)	= 0;	/* remove entry */
};	/* class Dictinoary */

}  /* namespace mydatastructure */

#endif
