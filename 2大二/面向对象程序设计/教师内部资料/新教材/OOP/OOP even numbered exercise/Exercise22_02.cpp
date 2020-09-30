#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename ElementType, typename ContainerType>
ElementType find(ContainerType &container, const ElementType &value)
{
  for (unsigned i = 0; i < container.size(); i++)
    if (container[i] == value)
      return i;

  return -1;
}

int main()
{
  int list1[] = {3, 5, 1, 0, 2, 8, 7, 6};
  vector<int> intVector(list1, list1 + 8);
  cout << "The maximum value in list1: " << (find<int, vector<int> >(intVector, 8)) << endl;
  return 0;
}
