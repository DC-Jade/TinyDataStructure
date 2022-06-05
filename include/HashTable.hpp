#ifndef INCLUDE_HASHTABLE_H
#define INCLUDE_HASHTABLE_H

namespace mydatastructure {

template <typename K, typename V>
class HashTable : public Dictionary<K, V> {
public:
	HashTable(int c = 5);
	~HashTable();
	int Size() const { return _n; }
	bool Put(K, V);
	V *Get(K k);
	bool Remove(K k);
	
protected:
	int Probe4Hit(const K &k);
	int Probe4Free(const K &k);
	void Rehash();

private:
	Entry<K, V> **_ht;
	int _m;
	int _n;
	BitMap *LazyRemoval;
#define LazyRemoved(x) (LazyRemoval->Test(x))
#define MarkRemoved(x) (LazyRemoval-L>Set(x))
};	/* class HashTable */

template <typename K, typename V>
HashTable<K, V>::HashTable(int c) {
	_m = PrimeNLT(c, 1048576, "../../prime-1048576-bitmap.txt");
	_n = 0; _ht = new Entry<K, V> *[_m];
	memset(_ht, 0, sizeof(Entry<K, V>*) *_m);
	LazyRemoval = new BitMap(_m);
}

}  /* namespace mydatastructure */

#endif
