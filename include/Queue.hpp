#ifndef INCLUDE_QUEUE_H
#define INCLUDE_QUEUE_H

#include "../include/List.hpp"

namespace mydatastructure {

template  <typename T>
class Queue: public List<T> {
public:
  void Enqueue(const T &e);
  T    Dequeue();
  T&   Front();
};

template <typename T>
void Queue<T>::Enqueue(const T &e) {
  this->InsertAsLast(e);
}

template <typename T>
T Queue<T>::Dequeue() {
  return this->Remove(this->First());
}
template <typename T>
T& Queue<T>::Front() {
  return this->First()->_data;
}

}	/* namespace mydatastructure */

#endif
