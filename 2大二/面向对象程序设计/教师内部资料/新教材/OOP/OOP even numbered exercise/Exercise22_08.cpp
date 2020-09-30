#include <iostream>
#include <set>
using namespace std;

template<typename ElementType>
void difference(set<ElementType> &s1, 
  set<ElementType> &s2, set<ElementType> &s3)
{
  for (set<ElementType>::iterator p = s1.begin(); p != s1.end(); p++)
  {
    set<ElementType>::iterator p1 = s2.find(*p);

    if (p1 == s2.end()) 
      s3.insert(*p);
  }
}

int main()
{
  set<int> s1;
  s1.insert(10);
  s1.insert(11);

  set<int> s2;
  s2.insert(10);
  s2.insert(12);

  set<int> s3;

  difference<int>(s1, s2, s3);
  for (set<int>::iterator p = s3.begin(); p != s3.end(); p++)
  {
	cout << *p << " ";
  }
  cout << endl;

  return 0;
}
