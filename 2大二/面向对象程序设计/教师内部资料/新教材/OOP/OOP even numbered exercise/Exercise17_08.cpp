#include <iostream>
using namespace std;

void reverseDisplay(int value)
{
  if (value != 0)
  {
    cout << value % 10;
    value = value / 10;
    reverseDisplay(value);
  }
}

int main()
{
  cout << "Enter an integer: ";
  int n;
  cin >> n;

  reverseDisplay(n);

  return 0;
}
