#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"
#include <stdexcept>
using namespace std;

template<typename T>
class Queue : public LinkedList<T>
{
public:
  Queue();
  void enqueue(T element);
  T dequeue() throw (runtime_error);
  int getSize();
};

template<typename T>
Queue<T>::Queue()
{
}

template<typename T>
void Queue<T>::enqueue(T element)
{
  addLast(element);
}

template<typename T>
T Queue<T>::dequeue() throw (runtime_error)
{
  return removeFirst();
}

template<typename T>
int Queue<T>::getSize()
{
  return getSize();
}

#endif

int main()
{
  Queue<int> q;
  q.enqueue(4);
  q.enqueue(5);

  cout << q.dequeue() << endl;
  return 0;
}
