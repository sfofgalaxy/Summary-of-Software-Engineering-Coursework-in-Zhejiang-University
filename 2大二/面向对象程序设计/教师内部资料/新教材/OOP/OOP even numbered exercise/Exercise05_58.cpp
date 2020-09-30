#include <iostream>
using namespace std;

int main()
{
  cout << "Enter a positive integer: ";
  int n;
  cin >> n;

  int number = n;
  int factor = 2;
  int coefficient = 1;
  while (factor <= number)
  {
    if (number % (factor * factor) == 0)
    {
      coefficient *= factor;
      number = number / (factor * factor);
    }
    else
      factor++;
  }

  cout << "sqrt(" << n << ") is ";

  if (n == 1)
    cout << 1 << endl;

  if (coefficient > 1)
    cout << coefficient; 

  if  (coefficient > 1 && number > 1)
    cout << "*";

  if (number > 1)
    cout << "sqrt(" << number << ")" << endl;
  
  return 0;
}
