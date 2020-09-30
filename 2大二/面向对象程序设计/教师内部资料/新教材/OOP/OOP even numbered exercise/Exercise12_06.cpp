#include <iostream>
using namespace std;

#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack
{
public:
  Stack();
  bool empty();
  T peek();
  T push(T value);
  T pop();
  int getSize();
  void printStack();

private:
  T elements[100];
  int size;
};

template<typename T>
Stack<T>::Stack()
{
  size = 0;
}

template<typename T>
bool Stack<T>::empty()
{
  return (size == 0);
}

template<typename T>
T Stack<T>::peek()
{
  return elements[size - 1];
}

template<typename T>
T Stack<T>::push(T value)
{
  return elements[size++] = value;
}

template<typename T>
T Stack<T>::pop()
{
  return elements[--size];
}

template<typename T>
int Stack<T>::getSize()
{
  return size;
}

template<typename T>
void Stack<T>::printStack()
{
  for (int i = 0; i < getSize(); i++)
    cout << elements[i] << " ";
}
#endif

int main()
{
  Stack<int> s;
  s.push(1);
  s.push(2);

  s.printStack();

  cout << "Done" << endl;
}
