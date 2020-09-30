#include <iostream>
#include <vector>
using namespace std;

template<typename ElementType, typename ContainerType>
void reverse(ContainerType &container)
{
  ContainerType::iterator p1 = container.begin();
  ContainerType::iterator p2 = container.end() - 1;
  for (; p1 < p2; p1++, p2--)
  {
    ElementType temp = *p1;
    *p1 = *p2;
	*p2 = temp; 
	
  }
}

int main()
{
  int list1[] = {3, 5, 1, 8, 2, 8, 7, 6};
  vector<int> intVector(list1, list1 + 8);
  reverse<int, vector<int> >(intVector);

  for (unsigned i = 0; i < intVector.size(); i++)
    cout << intVector[i] << " ";
 
  cout << endl;

  return 0;
}
