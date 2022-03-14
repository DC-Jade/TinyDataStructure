#ifndef DATA_STRUCTURE_LIST_H 

#include <iostream>
template <typename T>
const T& max(const T &value1, const T &value2) {
  return (value1 > value2) ? value1 : value2;
}
namespace mydatastructure {

#define DEFAULT_CAPACITY 10 
typedef int Rank;

template <typename T> class Vector {

public:
  Vector(int c = DEFAULT_CAPACITY);
  Vector(Vector<T> const &vec);
  ~Vector();

  T& operator[](Rank r);
  void traverse();
  // Vector(const T &arr, Rank lo, Rank hi)
  // {
  // copyFrom(arr, lo, hi);
  // }
  Rank getSize() const {
    return _size;
  }
  Rank getCapacity() {
    return _capacity;
  }
  void expand();
  Rank insert(Rank r, const T& e);
  int remove(Rank lo, Rank hi);
  T remove(Rank r);

private:
  Rank _size; 
  Rank _capacity;
  T *_elem; //data array
};

}

template <typename T>
mydatastructure::Vector<T>::Vector(int c) {
  _elem = new T[_capacity = c];
  _size = 0;
  std::cout << "default constructor of Vector" << std::endl;
}

template <typename T>
mydatastructure::Vector<T>::Vector(const Vector<T> &vec) {
  this->_size = vec->_size;
  this->_capacity = vec->_capacity;
  for (Rank i = 0; i < _size; ++i) {
    this[i] = vec[i];
  }
}

template <typename T>
mydatastructure::Vector<T>::~Vector(){
  std::cout << "deconstructor of Vector" << std::endl;
}

template <typename T>
T& mydatastructure::Vector<T>::operator[](Rank r) {
  return _elem[r];
}

template <typename T>
void mydatastructure::Vector<T>::traverse() {
  // Vector<int> iv;
  std::cout << "traverse " << std::endl;
  for (int i = 0; i < _size; ++i)
  {
    std::cout << _elem[i] << "\t";
  }
  std::cout << std::endl;
}

template <typename T>
void mydatastructure::Vector<T>::expand() {
  if (_size < _capacity) return;
  _capacity = max(_capacity, DEFAULT_CAPACITY);
  T *old_elem = _elem;
  _elem = new T[_capacity << 1];  // multiple two
  for (int i = 0; i < _size; ++i) 
    _elem[i] = old_elem[i];
  delete [] old_elem;
  _capacity = _capacity << 1;
}

template <typename T>
mydatastructure::Rank mydatastructure::Vector<T>::insert(Rank r, const T& e) {
  expand();
  for (Rank i = _size; i > r; --i) {
    _elem[i] = _elem[i - 1];
  }
  _elem[r] = e;
  ++_size;
  return r;
}

// remove [lo, hi)
template <typename T>
int mydatastructure::Vector<T>::remove(
  mydatastructure::Rank lo,                                    mydatastructure::Rank hi) {
    if (lo == hi) return 0;
    while (hi < _size)
    {
      _elem[lo++] = _elem[hi++];
    }
    _size = lo;
    return (hi - lo);
}

// remove single value
template <typename T>
T mydatastructure::Vector<T>::remove(Rank r) {
  T old_e = _elem[r];
  remove(r, r + 1);
  return old_e;
}

#endif
