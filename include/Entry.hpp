#ifndef INCLUDE_ENTRY_H
#define INCLUDE_ENTRY_H

#include <stdio.h>

namespace mydatastructure {

template <typename K, typename V>
class Entry {
public:
  K _key;
  V _value;

  Entry(K k = K(), V v = V()) : _key(k), _value(v) {
    printf("%s\n", "Entry default constructor");
  };
  Entry(const Entry<K, V> &e) : _key(e.key), _value(e._value) {};
  
  bool operator<(const Entry<K, V> &e) { return this->_key < e._key; }
  bool operator>(const Entry<K, V> &e) { return this->_key > e._key; }
  bool operator==(const Entry<K, V> &e) { return this->_key == e._key; }
  bool operator!=(const Entry<K, V> &e) { return this->_key != e._key; }
};  // class Entry<K, V>

}  // namespace mydatastructure






#endif