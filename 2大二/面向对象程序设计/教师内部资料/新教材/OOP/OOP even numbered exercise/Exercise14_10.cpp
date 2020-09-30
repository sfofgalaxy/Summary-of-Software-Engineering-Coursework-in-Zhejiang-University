#include <iostream>
#include "RationalWithOperators.h"
#include <string>
using namespace std;

int getDenominator(int size)
{
  int result = 1;
  for (int i = 0; i < size; i++)
    result *= 10;
  return result;
}

Rational getFraction(string& decimal)
{
  int position = decimal.find(".");
  if (position == string::npos)
    return Rational(atoi(decimal.data()), 1);

  string integerPart = decimal.substr(0, position);
  string fractionalPart = decimal.substr(position + 1);
  string nominator = integerPart + fractionalPart;

  return Rational(atoi(nominator.data()), getDenominator(fractionalPart.size()));
}

int main() {
  string decimal;
  cout << "Enter a decimal: ";
  getline(cin, decimal);

  cout << "The fraction number is " << getFraction(decimal) << endl;

  return 0;
}