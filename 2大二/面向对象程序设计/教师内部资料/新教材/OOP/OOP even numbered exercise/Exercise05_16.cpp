#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  // Enter n1

  cout << "Enter the first number: ";

  int n1;
  cin >> n1;

  // Enter n2
  cout << "Enter the second number: ";

  int n2;
  cin >> n2;

  int d = (n1 < n2) ? n1 : n2;
  for ( ; d >= 1; d--)
    if ((n1 % d == 0) && (n2 % d == 0))
      break;

  cout << "GCD of " << n1 << " and " << n2 << " is " << d;

  return 0;
}
