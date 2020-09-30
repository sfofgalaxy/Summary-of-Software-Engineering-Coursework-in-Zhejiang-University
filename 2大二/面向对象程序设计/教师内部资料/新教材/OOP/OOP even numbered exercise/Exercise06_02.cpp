#include <iostream>
#include <cmath>
using namespace std;

int sumDigits(long n)
{
  int temp = abs(n);
  int sum = 0;

  while (temp != 0)
  {
    int remainder = temp % 10;
    sum += remainder;
    temp = temp / 10;
  }

  return sum;
}

int main()
{
  cout << "Enter an integer: ";
  int n;
  cin >> n;

  cout << "The sum of digits for " << n << " is " << sumDigits(n) << endl;

  return 0;
}
