#include <iostream>
#include <map>
using namespace std;

int main()
{
  map<int, int> map1;

  cout << "Enter numbers (ending with 0): ";
  int number;
  cin >> number;

  map<int, int>::iterator p;

  while (number != 0)
  {
    p = map1.find(number);
    if (p == map1.end()) // number not in map1
    {
      map1.insert(map<int, int>::value_type(number, 1));
    }
    else
    {
      int count = p->second;
          count++;
          map1.erase(number);
          map1.insert(map<int, int>::value_type(number, count));
    }

    cin >> number;
  }

  for (p = map1.begin(); p != map1.end(); p++)
    cout << "number of occurrences for " << p->first << " is " << p->second << endl;

  return 0;
}
