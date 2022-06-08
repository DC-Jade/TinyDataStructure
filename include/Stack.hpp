#ifndef INCLUDE_STACK_H
#define INCLUDE_STACK_H

#include "../include/Vector.hpp"

namespace mydatastructure {

template <typename T>
class Stack: public Vector<T> {
public:
  //int Size();
  void Push(const T &e);
  T    Pop();
  T&   Top();
  bool Empty();
}; // class Stack<T>

template <typename T>
void Stack<T>::Push(const T &e) {
  this->Insert(e);
}

template <typename T>
T Stack<T>::Pop() {
  return this->Remove(this->Size() - 1);
}

template <typename T>
T& Stack<T>::Top() {
  return (*this)[this->Size() - 1];
}

template <typename T>
bool Stack<T>::Empty() {
  return (this->Size() == 0) ? true : false;
}

}	/* namespace mydatastructure */

#endif
