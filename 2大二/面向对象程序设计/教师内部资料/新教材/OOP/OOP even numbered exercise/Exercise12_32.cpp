#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
int indexOf(vector<T> v, T name) 
{
  for (int i = 0; i < v.size(); i++)
    if (v[i] == name)
      return i;
    
  return -1;
}

// A more efficient way to implement it is to use an iterator, introduced later in book on STL algorithms
template<typename T>
void removeDuplicate(vector<T>& v)
{
  vector<T> temp;
  for (int i = 0; i < v.size(); i++)
    if (indexOf(temp, v[i]) < 0)
      temp.push_back(v[i]);

  v = temp;
}

int main()
{
  cout << "Enter ten integers: ";
  vector<int> v(10);
  for (int i = 0; i < 10; i++)
    cin >> v[i];


  removeDuplicate(v);
  cout << "The distinct integers are ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  cout << endl;

  return 0;
}