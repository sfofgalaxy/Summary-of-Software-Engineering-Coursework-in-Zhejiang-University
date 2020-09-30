#include <iostream>
using namespace std;



class StackOfIntegers
{
public:
  StackOfIntegers::StackOfIntegers()
  {
    size = 0;
  }

  bool StackOfIntegers::empty()
  {
    return (size == 0);
  }

  int StackOfIntegers::peek()
  {
    return elements[size - 1];
  }

  int StackOfIntegers::push(int value)
  {
    return elements[size++] = value;
  }

  int StackOfIntegers::pop()
  {
    return elements[--size];
  }

  int StackOfIntegers::getSize()
  {
    return size;
  }

  int & StackOfIntegers::operator[] (const int & index)
  {
    return elements[index];
  }


private:
  int elements[100];
  int size;
};



int main()
{
  StackOfIntegers s;
  s.push(1);
  s.push(2);

  s[0] = 999;
  cout << s[0] << endl;

  return 0;
}
