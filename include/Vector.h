#ifndef DATA_STRUCTURE_LIST_H 
#define DATA_STRUCTURE_LIST_H 
  
#include <iostream>

template <typename T>
const T& Max(const T &value1, const T &value2) {
  return (value1 > value2) ? value1 : value2;
}

template <typename T>
class Increase{
  virtual void operator()(T& e) { e++;  }
};

// TODO
class Bitmap;

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
  void Tranverse();
  Rank GetSize() const { return _size; }
  Rank GetCapacity() { return _capacity; }
  void Expand();
  Rank Insert(Rank r, const T& e);
  int  Remove(Rank lo, Rank hi);  // Remove [lo, hi)
  T    Remove(Rank r);            // Remove [r, r + 1)
  Rank Find(const T& e, Rank lo, Rank hi) const;
  Rank Find(const T& e) const;
  int  Deduplicate();
  void Tranverse(void ( *visit )( T& ));
  int  Uniquify();
  Rank Search(const T &e, Rank lo, Rank hi) const;
  Rank Search(const T &e) const;
  void Sort(Rank lo, Rank hi);
  // assert: 0 <= lo < hi <= _size
  void BubbleSort(Rank lo, Rank hi);
  void Merge(Rank lo, Rank mi, Rank hi);
  void MergeSort(Rank lo, Rank hi);
  void MergeSort();  // MergeSort(0, _size)
  // NEXT

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
void mydatastructure::Vector<T>::Tranverse() {
  // Vector<int> iv;
  std::cout << "Tranverse " << std::endl;
  for (int i = 0; i < _size; ++i)
  {
    std::cout << _elem[i] << "\t";
  }
  std::cout << std::endl;
}

template <typename T>
void mydatastructure::Vector<T>::Expand() {
  if (_size < _capacity) return;
  _capacity = Max(_capacity, DEFAULT_CAPACITY);
  T *old_elem = _elem;
  _elem = new T[_capacity << 1];  // multiple two
  for (int i = 0; i < _size; ++i) 
    _elem[i] = old_elem[i];
  delete [] old_elem;
  _capacity = _capacity << 1;
}

template <typename T>
mydatastructure::Rank mydatastructure::Vector<T>::Insert(Rank r, const T& e) {
  Expand();
  for (Rank i = _size; i > r; --i) {
    _elem[i] = _elem[i - 1];
  }
  _elem[r] = e;
  ++_size;
  return r;
}

// Remove [lo, hi)
template <typename T>
int mydatastructure::Vector<T>::Remove(
  mydatastructure::Rank lo,                                    mydatastructure::Rank hi) {
    if (lo == hi) return 0;
    while (hi < _size)
    {
      _elem[lo++] = _elem[hi++];
    }
    _size = lo;
    return (hi - lo);
}

// Remove single value
template <typename T>
T mydatastructure::Vector<T>::Remove(Rank r) {
  T old_e = _elem[r];
  Remove(r, r + 1);
  return old_e;
}

// assert: 0<= lo < hi <= _size
template <typename T>
mydatastructure::Rank mydatastructure::Vector<T>::Find(const T& e, 
                                                       Rank lo, 
                                                       Rank hi) const {
  // reverse Find, to maintain stable
  while ( (lo < hi--) && (e != _elem[hi]) ) { }  
  return (lo < hi) ? hi : -1;    // false -1
}

template <typename T>
mydatastructure::Rank mydatastructure::Vector<T>::Find(const T& e) const {
  return Find(e, 0, _size);
}

template <typename T>
int mydatastructure::Vector<T>::Deduplicate() {
  Rank old_size = _size;
  for (Rank i = 0; i < _size;) {
    if ( Find(_elem[i], 0, i) == -1 )
      ++i;
    else
      Remove(i);
  }
  return old_size - _size;
}

// TODO
template <typename T>
void mydatastructure::Vector<T>::Tranverse(void ( *visit )( T& )) {
  for (Rank i = 0; i < _size; ++i)
    visit(_elem[i]);
}

template <typename T>
void increase( mydatastructure::Vector<T>& vec) {
  vec.Tranverse(Increase<T>());
}

// TODO
//template <typename T> 
//void checkOrder(mydatastructure::Vector<T>& vec) {
//  int unSorted = 0;
//  vec.Tranverse( CheckOrder<T>(unSorted, vec[0]) );
//  if (0 < unSorted) 
//    printf("UnSorted with %d adjacent inversion(s)\n", unSorted);
//  else 
//    printf("Sorted\n");
//}

template <typename T>
int mydatastructure::Vector<T>::Uniquify() {
  int old_size = _size;
  for (int i = 1; i < _size; )
    _elem[i - 1] == _elem[i] ? Remove(i) : ++i;
  return old_size - _size;
}

// assert: 0 <= lo < hi <=_size
template <typename T>
mydatastructure::Rank mydatastructure::Vector<T>::Search(
  const T& e, Rank lo, Rank hi ) const {
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
mydatastructure::Rank mydatastructure::Vector<T>::Search(const T &e) const {
  return binSearch(_elem, e, 0, _size);
}

template <typename T>
void swap(T& lhs, T& rhs) {
  T tmp;
  tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}

// assert: 0 <= lo < hi <= _size
template <typename T>
void mydatastructure::Vector<T>::BubbleSort(
  mydatastructure::Rank lo,
  mydatastructure::Rank hi) {
  while (lo < --hi) {
    for (mydatastructure::Rank i = lo; i < hi; i++) 
      if (_elem[i] > _elem[i + 1]) {
        //int lhs = _elem[i];
        //int rhs = _elem[i + 1];
        swap(_elem[i], _elem[i + 1]);
        //lhs = _elem[i];
        //rhs = _elem[i + 1];
      }    
    
  }
}

template <typename T>
void mydatastructure::Vector<T>::Merge(
  // setp1: split two ordered part lvec[lo, mi) & rvec[mi, hi)
  mydatastructure::Rank lo,
  mydatastructure::Rank mi,
  mydatastructure::Rank hi) {
  mydatastructure::Rank i = 0;
  T *target_vec = _elem + lo;  // target_vec = _elem[lo, hi)
  mydatastructure::Rank j = 0;
  mydatastructure::Rank lvec_len = mi - lo;  //left vector length
  T *lvec = new T[lvec_len];
  for (mydatastructure::Rank i = 0; i < lvec_len; ++i)
    lvec[i] = target_vec[i];
  mydatastructure::Rank k = 0, rvec_len = hi - mi;
  T *rvec = _elem + mi;  // rvec[0, rvec_len] = _elem[mi, hi]

  // step2: Merge left and right vector
  while ( (j < lvec_len) && (k < rvec_len) )  // lvec become empty before rvec & lvec is lower than rvec default
    target_vec[i++] = (lvec[j] < rvec[k]) ? lvec[j++] : rvec[k++];
  while (j < lvec_len)  // rvec become empty  before lvec
    target_vec[i++] = lvec[j++];
  delete[] lvec;
}

template <typename T>
void mydatastructure::Vector<T>::MergeSort(
  mydatastructure::Rank lo,
  mydatastructure::Rank hi){
  if (hi - lo < 2) return;
  //int mi = lo + ((hi - lo) >> 1);
  int mi = (lo + hi) >> 1;
  MergeSort(lo, mi);
  MergeSort(mi, hi);
  Merge(lo, mi, hi);
}

template <typename T>
void mydatastructure::Vector<T>::Sort(
  mydatastructure::Rank lo,
  mydatastructure::Rank hi) {
  switch (rand() % 2) {
    case 0:
      BubbleSort(lo, hi);
      break;
    case 1:
      BubbleSort(lo, hi);
      break;
  }  
}

template <typename T>
void mydatastructure::Vector<T>::MergeSort() {
  MergeSort(0, _size);
}

#endif
