#include <iostream>
using namespace std;

long fib(int n) 
{
  int f0 = 0, f1 = 1, currentFib;

  if (n == 0) return 0;
  if (n == 1) return 1;

  for (int i = 2; i <= n; i++)
  {
    currentFib = f0 + f1;
    f0 = f1;
    f1 = currentFib;
  }

  return currentFib;
}

int main()
{
  cout << "Enter an index for the Fibonacci number: ";
  int index;
  cin >> index;

  // Display factorial
  cout << "Fibonacci number at index " << index << " is "
    << fib(index) << endl;
    
 return 0;
}