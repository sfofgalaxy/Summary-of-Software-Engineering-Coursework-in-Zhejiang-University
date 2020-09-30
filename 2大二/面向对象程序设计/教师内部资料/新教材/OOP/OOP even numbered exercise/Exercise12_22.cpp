#include <iostream>
#include <vector>
using namespace std;

bool isConsecutiveFour(const vector<int>& values)
{
  for (int i = 0; i < values.size() - 3; i++)
  {
    bool isEqual = true;
    for (int j = i; j < i + 3; j++)
    {
      if (values[j] != values[j + 1])
      {
        isEqual = false;
        break;
      }
    }

    if (isEqual) return true;
  }

  return false;
}

int main()
{
  cout << "Enter the number of values: ";
  int size;
  cin >> size;

  vector<int> values(size);

  cout << "Enter the values: ";
  for (int i = 0; i < values.size(); i++)
    cin >> values[i];

  cout << (isConsecutiveFour(values) ? "true" : "false") << endl;

  return 0;
}
