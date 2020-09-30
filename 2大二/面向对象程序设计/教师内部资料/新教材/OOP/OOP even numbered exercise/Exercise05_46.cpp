#include <iostream>
using namespace std;

int main()
{
  cout << "Enter an integer: ";
  int value;
  cin >> value;

  cout << "The 16 bits are ";
  int mask = 1;
  for (int i = 15; i >= 0; i--)
  {
    int temp = value >> i;
    int bit = temp & mask;
    cout << bit;
  }

  return 0;
}
