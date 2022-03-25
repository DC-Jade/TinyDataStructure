#include "../include/Vector.h"

namespace mydatastructure {
template <typename T>
class Stack: public Vector<T> {
public:
  void Size();
  void Push(const T &e);
  T    Pop();
  T&   Top();
  void GetMax();
  void Empty();
}; // class Stack<T>

template <typename T>
void Stack<T>::Push(const T &e) {
  insert(e)
}

}  // namespace mydatastructure