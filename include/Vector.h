#ifndef DATA_STRUCTURE_LIST_H 
  
#include <iostream>
template <typename T>
const T& max(const T &value1, const T &value2) {
  return (value1 > value2) ? value1 : value2;
}
template <typename T>
class Increase{
  virtual void operator()(T& e) { e++;  }
};

namespace mydatastructure {

#define DEFAULT_CAPACITY 10 
typedef int Rank;

template <typename T> class Vector {

public:
  Vector(int c = DEFAULT_CAPACITY);
  Vector(Vector<T> const &vec);
  ~Vector();

  Vector<T> &operator=(const Vector<T> &vec);
  T &operator[](Rank r);
  void traverse();
  Rank getSize() const { return _size; }
  Rank getCapacity() { return _capacity; }
  void expand();
  Rank insert(Rank r, const T& e);
  int  remove(Rank lo, Rank hi);
  T    remove(Rank r);
  Rank find(const T& e, Rank lo, Rank hi) const;
  Rank find(const T& e) const;
  int  deduplicate();
  void traverse(void ( *visit )( T& ));
  int  uniquify();
  Rank search(const T &e, Rank lo, Rank hi) const;
  Rank search(const T &e) const;

private:
  Rank _size; 
  Rank _capacity;
  T *_elem; //data array
};

}

// TODO
//template <typename T>
//mydatastructure::Vector<T>& mydatastructure::Vector<T>::operator=(
//  const mydatastructure::Vector<T>& vec) {
//  Vector<T> new_vec(_size);
//  for (Rank i = 0; i < _size; ++i)
//    new_vec[i] = _elem[i];
//  return new_vec;
//}

template <typename T>
mydatastructure::Vector<T>::Vector(int c) {
  _elem = new T[_capacity = c];
  _size = 0;
  std::cout << "default constructor of Vector" << std::endl;
}

// TODO
template <typename T>
mydatastructure::Vector<T>::Vector(const Vector<T> &vec) {
  _size = vec._size;
  _capacity = vec._capacity;
  for (Rank i = 0; i < _size; ++i) {
    _elem[i] = vec[i];
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

// assert: 0<= lo < hi <= _size
template <typename T>
mydatastructure::Rank mydatastructure::Vector<T>::find(const T& e, 
                                                       Rank lo, 
                                                       Rank hi) const {
  // reverse find, to maintain stable
  while ( (lo < hi--) && (e != _elem[hi]) ) { }  
  return (lo < hi) ? hi : -1;    // false -1
}

template <typename T>
mydatastructure::Rank mydatastructure::Vector<T>::find(const T& e) const {
  return find(e, 0, _size);
}

template <typename T>
int mydatastructure::Vector<T>::deduplicate() {
  Rank old_size = _size;
  for (Rank i = 0; i < _size;) {
    if ( find(_elem[i], 0, i) == -1 )
      ++i;
    else
      remove(i);
  }
  return old_size - _size;
}

// TODO
template <typename T>
void mydatastructure::Vector<T>::traverse(void ( *visit )( T& )) {
  for (Rank i = 0; i < _size; ++i)
    visit(_elem[i]);
}

template <typename T>
void increase( mydatastructure::Vector<T>& vec) {
  vec.traverse(Increase<T>());
}

// TODO
//template <typename T> 
//void checkOrder(mydatastructure::Vector<T>& vec) {
//  int unsorted = 0;
//  vec.traverse( CheckOrder<T>(unsorted, vec[0]) );
//  if (0 < unsorted) 
//    printf("Unsorted with %d adjacent inversion(s)\n", unsorted);
//  else 
//    printf("Sorted\n");
//}

template <typename T>
int mydatastructure::Vector<T>::uniquify() {
  int old_size = _size;
  for (int i = 1; i < _size; )
    _elem[i - 1] == _elem[i] ? remove(i) : ++i;
  return old_size - _size;
}

// assert: 0 <= lo < hi <=_size
template <typename T>
mydatastructure::Rank mydatastructure::Vector<T>::search(
  const T& e, Rank lo, Rank hi ) const {
  //return (rand() % 2) ? binSearch(_elem, e, lo, hi)
  //                    : fibSearch(_elem, e, lo, hi);
  binSearch(_elem, e, lo, hi);
}

template <typename T>
static mydatastructure::Rank binSearch(
  T* vec, const T& e,
  mydatastructure::Rank lo, mydatastructure::Rank hi) {
  while (lo < hi) {
    mydatastructure::Rank mi = (lo + hi) >> 1;
    if (e < vec[mi])
      hi = mi;
    else if (vec[mi] < e)
      lo = mi + 1;
    else
      return mi;
  }
  return -1;  // false
}

template <typename T>
mydatastructure::Rank mydatastructure::Vector<T>::search(const T &e) const {
  return binSearch(_elem, e, 0, _size);
}
#endif
