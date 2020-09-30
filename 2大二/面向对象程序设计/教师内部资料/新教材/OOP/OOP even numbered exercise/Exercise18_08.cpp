#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
  // A list to hold prime numbers
  const long N = 10000002; // Find primes up to N
  fstream inout;
  inout.open("Exercise18_7.dat", ios::in | ios::out | ios::binary);

  const int NUMBER_PER_LINE = 10; // Display 10 per line
  int count = 0; // Count the number of prime numbers
  int number = 2; // A number to be tested for primeness
  // A vector to hold prime numbers
  vector<int> primeVector;
  int squareRoot = 1; // Check whether number <= squareRoot

  // Repeatedly find prime numbers
  while (number <= N)
  {
    // Assume the number is prime
    bool isPrime = true; // Is the current number prime?

    if (squareRoot * squareRoot < number) squareRoot++;

    // Test if number is prime
    for (int k = 0; k < primeVector.size()
                    && primeVector.at(k) <= squareRoot; k++) {
      if (number % primeVector.at(k) == 0) { // If true, not prime
        isPrime = false; // Set isPrime to false
        break; // Exit the for loop
      }
    }

    // Print the prime number and increase the count
    if (isPrime) {
      count++; // Increase the count
      primeVector.push_back(number); // Add a new prime to the list
      inout.write(reinterpret_cast < char * > (& number), sizeof(long));
    }

    // Check if the next number is prime
    number++;
  }

  inout.close();

  cout << "done" << endl;
  return 0;
}
