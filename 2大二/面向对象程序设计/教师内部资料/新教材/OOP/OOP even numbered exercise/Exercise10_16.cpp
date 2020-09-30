#include <iostream>
#include "StackOfIntegers.h"
using namespace std;

int main()
{
  StackOfIntegers stack;

  // Prompt the user to enter an integer
  cout << "Enter an integer: ";
  int number;
  cin >> number;

  // Find and store all the smallest factors of the integer
  int factor = 2;
  while (factor <= number)
  {
    if (number % factor == 0)
    {
      number = number / factor;
      stack.push(factor);
    }
    else
    {
      factor++;
    }
  }

  // Display factors
  cout << "The factors for " << number << " is ";
  while (!stack.isEmpty())
  {
    cout << stack.pop() << " ";
  }

  return 0;
}
