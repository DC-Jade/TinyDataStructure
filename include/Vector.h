#ifndef DATA_STRUCTURE_LIST_H 

#include <iostream>

namespace mydatasturcture {

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

private:
  Rank _size; 
  Rank _capacity;
  T *_elem; //data array
};

}

template <typename T>
mydatasturcture::Vector<T>::Vector(int c) {
  _elem = new T[_capacity = c];
  _size = 0;
  std::cout << "default constructor of Vector" << std::endl;
}

template <typename T>
mydatasturcture::Vector<T>::Vector(const Vector<T> &vec) {
  this->_size = vec->_size;
  this->_capacity = vec->_capacity;
  for (Rank i = 0; i < _size; ++i) {
    this[i] = vec[i];
  }
}

template <typename T>
mydatasturcture::Vector<T>::~Vector(){
  std::cout << "deconsturctor of Vector" << std::endl;
}

template <typename T>
T& mydatasturcture::Vector<T>::operator[](Rank r) {
  return _elem[r];
}

template <typename T>
void mydatasturcture::Vector<T>::traverse() {
  // Vector<int> iv;
  std::cout << "traverse " << std::endl;
  for (int i = 0; i < _size; ++i)
  {
    std::cout << _elem[i] << "\t";
  }
  std::cout << std::endl;
}

#endif