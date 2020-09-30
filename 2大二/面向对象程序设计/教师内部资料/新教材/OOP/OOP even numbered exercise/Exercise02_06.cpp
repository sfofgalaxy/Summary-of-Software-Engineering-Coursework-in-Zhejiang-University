#include <iostream>
using namespace std;

int main()
{
  cout << "Enter a number between 0 and 1000: ";
  int number;
  cin >> number;

  int lastDigit = number % 10;
  number = number / 10;

  int secondLastDigit = number % 10;
  number = number / 10;

  int thirdLastDigit = number % 10;
  number = number / 10;

  int sumOfDigits = lastDigit + secondLastDigit + thirdLastDigit;

  cout << "The sum of the digits is " << sumOfDigits << endl;

  return 0;
}
