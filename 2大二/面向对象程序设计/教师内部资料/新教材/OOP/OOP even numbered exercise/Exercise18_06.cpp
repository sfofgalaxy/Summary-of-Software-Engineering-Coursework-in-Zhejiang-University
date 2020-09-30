#include <iostream>
#include <string>
using namespace std;

/** The function for finding the Fibonacci number */
long fib(long n)
{
  if (n == 0 || n == 1)
    return n;

  long f0 = 0; // For fib(0)
  long f1 = 1; // For fib(1)
  long currentFib = 1; // For fib(2)

  for (int i = 2; i <= n; i++)
  {
    currentFib = f0 + f1;
    f0 = f1;
    f1 = currentFib;
  }

  return currentFib;
}

/** From Listing 18.2: Find gcd for intergers m and n */
int gcd1(int m, int n)
{
  int gcd = 1;

  if (m == n) return m;

  for (int k = 1; k <= m / 2 && k <= n / 2; k++)
  {
    if (m % k == 0 && n % k == 0)
      gcd = k;
  }

  return gcd;
}

/** From Listing 18.3: Find gcd for intergers m and n */
int gcd2(int m, int n)
{
  if (m % n == 0)
    return n;
  else
    return gcd2(n, m % n);
}


int main()
{
  // Find the first 180000 Fibonacci numbers
  const int INDEX = 180;
  int numbers[INDEX];
  numbers[0] = 0;
  numbers[1] = 1;
  for (int i = 2; i < INDEX; i++)
  {
    numbers[i] = numbers[i - 1] + numbers[i - 2];
  }

  cout << "\t\t\t40\t41\t42\t43\t44\t45" << endl;
  cout << "-----------------------------------------------" << endl;
  cout << "Listing 18.2 GCD1";

  long executionTime[6];
  long startTime = time(0);

  for (int i = 40; i <= 45; i++)
  {
    gcd1(numbers[i], numbers[i + 1]);
    executionTime[i - 40] = time(0) - startTime;
  }

  for (int i = 0; i <= 5; i++)
  {
    cout << "\t" << executionTime[i];
  }

  cout << "\nListing 18.3 GCD2";

  startTime = time(0);
  for (int i = 40; i <= 45; i++)
  {
    gcd2(numbers[i], numbers[i + 1]);
    executionTime[i - 40] = time(0) - startTime;
  }

  for (int i = 0; i <= 5; i++)
  {
    cout << "\t" << executionTime[i];
  }

  return 0;
}
