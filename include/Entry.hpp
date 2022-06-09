#ifndef INCLUDE_ENTRY_H
#define INCLUDE_ENTRY_H

namespace mydatastructure {

template <typename K, typename V>
class Entry {
public:
	/* constructor */
	Entry();
	Entry(K key = K(), V value = V());
	Entry(const Entry<K, V> &entry);

	/* interface */
	bool operator<(const Entry<K, V> &entry);
	bool operator>(const Entry<K, V> &entry);
	bool operator==(const Entry<K, V> &entry);
	bool operator!=(const Entry<K, V> &entry);
	
	/* data member */
	K _key;
	V _value;
};	/* class Enetry<T> */

/* function member */
template <typename K, typename V>
Entry<K, V>::Entry() { 
	_key = K();
	_value = V();
}

template <typename K, typename V>
Entry<K, V>::Entry(K key, V value) : _key(key), _value(value) { }

template <typename K, typename V>
Entry<K, V>::Entry(const Entry<K, V> &entry) :
	_key(entry._key), _value(entry._value) { }

template<typename K, typename V>
bool Entry<K, V>::operator<(const Entry<K, V> &entry) {
	return this->_key < entry._key;
}

template<typename K, typename V>
bool Entry<K, V>::operator>(const Entry<K, V> &entry) {
	return this->_key > entry._key;
}

template<typename K, typename V>
bool Entry<K, V>::operator==(const Entry<K, V> &entry) {
	return this->_key == entry._key;
}

template<typename K, typename V>
bool Entry<K, V>::operator!=(const Entry<K, V> &entry) {
	return this->_key != entry._key;
}

}	/* namespace mydatastruture */

#endif
