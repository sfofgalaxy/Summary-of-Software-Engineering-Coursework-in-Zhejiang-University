#include <iostream>
//#include <cstring>
#include <stdexcept>
using namespace std;

class EmptyStackException : public runtime_error
{
public:
  EmptyStackException() : runtime_error("Empty Stack Exception")
  {
  }
};

class StackOfIntegers
{
public:
  StackOfIntegers();
  bool isEmpty() const;
  int peek() const;
  void push(int value);
  int pop();
  int getSize() const;

private:
  int elements[100];
  int size;
};

StackOfIntegers::StackOfIntegers()
{
  size = 0;
}

bool StackOfIntegers::isEmpty() const
{
  return (size == 0);
}

int StackOfIntegers::peek() const
{
  if (size == 0)
    throw EmptyStackException();

  return elements[size - 1];
}

void StackOfIntegers::push(int value)
{
  elements[size++] = value;
}

int StackOfIntegers::pop()
{
  if (size == 0)
    throw EmptyStackException();

  return elements[--size];
}

int StackOfIntegers::getSize() const
{
  return size;
}

int main()
{
  StackOfIntegers stack;

  try 
  {
    cout << stack.peek() << endl;
  }
  catch (EmptyStackException& ex)
  {
    cout << "Empty stack" << endl;
  }

  return 0;
}