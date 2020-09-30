#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class MyVector : public vector<T>
{
public:
  // Append an element to the vector
  void append(T element); 

  // Return true if the vector is empty
  bool isEmpty() const; 
};
#endif

template<typename T>
void MyVector<T>::append(T element)
{
  this->push_back(element);
}

template<typename T>
bool MyVector<T>::isEmpty() const
{
  return this->empty(); 
}

int main()
{
  MyVector<string> v;
  
  v.append("Beijing");
  v.append("New York");
  v.append("London");

  cout << "Is the vector empty? " 
    << (v.isEmpty()? "Yes" : "No") << endl;

  return 0;
}
