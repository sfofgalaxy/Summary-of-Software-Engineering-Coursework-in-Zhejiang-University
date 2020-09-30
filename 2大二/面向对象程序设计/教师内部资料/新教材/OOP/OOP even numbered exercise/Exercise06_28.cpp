#include <iostream>
using namespace std;

int getSize(int n)
{
  int numberOfDigits = 0;
  do
  {
    numberOfDigits++;
    n = n / 10;
  }
  while (n != 0);

  return numberOfDigits;
}

int main()
{
  cout << "Enter an integer: ";
  int n;
  cin >> n;
  cout << "The number of digits in " << n
    << " is " << getSize(n) << endl;

  return 0;
}
