#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  cout << "Enter a positive integer: ";

  int number;
  cin >> number;

  cout << "The factors for " << number << " is ";
  int factor = 2;
  while (factor <= number)
  {
    if (number % factor == 0)
    {
      number = number / factor;
      cout << factor << " ";
    }
    else
    {
      factor++;
    }
  }

  return 0;
}
