#include <iostream>
using namespace std;

template<typename T>
class MyVector
{
public:
  MyVector();
  void push_back(T element);
  void pop_back();
  unsigned int size();
  bool empty();
  T at(int index);
  void clear();
  void swap(MyVector v2);

private:
  T elements[100];
  int vectorSize;
};

template<typename T>
MyVector<T>::MyVector()
{
  vectorSize = 0;
}

template<typename T>
bool MyVector<T>::empty()
{
  return (vectorSize == 0);
}

template<typename T>
T MyVector<T>::at(int index)
{
  return elements[index];
}

template<typename T>
void MyVector<T>::push_back(T value)
{
  elements[vectorSize++] = value;
}

template<typename T>
void MyVector<T>::pop_back()
{
  return elements[--vectorSize];
}

template<typename T>
unsigned int MyVector<T>::size()
{
  return vectorSize;
}

template<typename T>
void MyVector<T>::clear()
{
  vectorSize = 0;
}

template<typename T>
void MyVector<T>::swap(MyVector v2)
{
  T temp[100];
  int tempSize = v2.size();
  for (int i = 0; i < v2.size(); i++)
    temp[i] = v2.at(i);

  v2.clear();
  for (int i = 0; i < size(); i++)
    v2.push_back(at(i));

  clear();
  for (int i = 0; i < tempSize; i++)
    push_back(temp[i]);
}

int main()
{
  MyVector<int> v1;
  v1.push_back(1);
  v1.push_back(2);

  MyVector<int> v2;
  v2.push_back(3);
  v2.push_back(4);
  v2.push_back(5);
  v2.push_back(6);
  v2.push_back(7);

  v1.swap(v2);

  for (int i = 0; i < v1.size(); i++)
    cout << v1.at(i) << " ";
}
