// Version 1. Enter the number as a string
#include <iostream>
#include <string>
using namespace std;

int main()
{
  // Prompt the user to enter an ISBN as a string
  cout << "Enter the first 9-digit of an ISBN number as a string: ";
  string s;
  cin >> s;

  if (s.size() != 9)
  {
    cout << "Incorrect input" << endl;
    exit(1);
  }

  // Calculate checksum
  int sum = 0;
  for (int i = 0; i < s.size(); i++)
    sum += (s[i] - '0') * (i + 1);

  int checksum = sum % 11;

  cout << "The ISBN number is ";

  cout << s;
  if (checksum == 10)
    cout << "X" << endl;
  else
    cout << checksum << endl;

  return 0;
}

// Version 2. Enter the number as an integer
/*
#include <iostream>
using namespace std;

int main()
{
  // Prompt the user to enter an integer
  cout << "Enter the first 9-digit of an ISBN number as integer: ";
  int number;
  cin >> number;

  // Calculate checksum
  int t = number;
  int i = 9;
  int sum = 0;

  while (t != 0)
  {
    sum += (t % 10) * i;
    i--;
    t = t / 10;
  }

  int checksum = sum % 11;

  cout << "The ISBN number is ";

  // Display leading zeros
  int temp = 100000000;
  while (number / temp == 0)
  {
    cout << "0";
    temp = temp / 10;
  }

  cout << number;
  if (checksum == 10)
    cout << "X";
  else
    cout << checksum;

  return 0;
}
*/