#include <iostream>
#include <vector>
using namespace std;

template<typename ElementType, typename ContainerType>
void replace(ContainerType &container,
  const ElementType &oldValue, const ElementType &newValue)
{
  ContainerType :: iterator p;
  for (p = container.begin(); p != container.end(); p++)
  {
    if (*p == oldValue)
      *p = newValue;
  }
}

int main()
{
  int list1[] = {3, 5, 1, 8, 2, 8, 7, 6};
  vector<int> intVector(list1, list1 + 8);
  replace<int, vector<int> >(intVector, 8, 77);
  
  for (unsigned i = 0; i < intVector.size(); i++)
    cout << intVector[i] << " ";
 
  cout << endl;

  return 0;
}
