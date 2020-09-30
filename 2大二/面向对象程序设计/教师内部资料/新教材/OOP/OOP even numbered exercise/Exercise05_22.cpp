#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  int count = 1; // Count the number of prime numbers
  int number = 2; // A number to be tested for primeness
  bool isPrime = true; // If the current number is prime?

  cout << "The prime numbers from 2 to 1000 are \n";

  // Repeatedly test if a new number is prime
  while (number <= 1000)
  {
    // Assume the number is prime
    isPrime = true;

    // Set isPrime to false, if the number is prime
    for (int divisor = 2; divisor <= number / 2; divisor++)
    {
      if (number % divisor == 0)
      { // If true, the number is prime
        isPrime = false;
        break; // Exit the for loop
      }
    }

    // Print the prime number and increase the count
    if (isPrime)
    {
      if (count % 8 == 0)
      {
        // Print the number and advance to the new line
        cout << setw(5) << number << endl;
      }
      else
        cout << setw(5) << number << " ";

      count++; // Increase the count
    }

    // Check if the next number is prime
    number++;
  }

  return 0;
}
