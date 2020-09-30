#ifndef NEWRATIONL_H
#define NEWRATIONL_H
#include <iostream>
using namespace std;

class Rational
{
public:
  Rational();
  Rational(long numerator, long denominator);
  long getNumerator();
  long getDenominator();
  Rational add(const Rational &secondRational);
  Rational subtract(const Rational &secondRational);
  Rational multiply(const Rational &secondRational);
  Rational divide(const Rational &secondRational);
  int compareTo(const Rational &secondRational);
  bool equals(const Rational &secondRational);
  int intValue();
  double doubleValue();
  string toString();

  // Define function operators for relational operators
  bool operator<(const Rational &secondRational);
  bool operator<=(const Rational &secondRational);
  bool operator>(const Rational &secondRational);
  bool operator>=(const Rational &secondRational);
  bool operator!=(const Rational &secondRational);
  bool operator==(const Rational &secondRational);

  // Define function operators for arithmetic operators
  Rational operator+(const Rational &secondRational);
  Rational operator-(const Rational &secondRational);
  Rational operator*(const Rational &secondRational);
  Rational operator/(const Rational &secondRational);

  // Define function operators for shorthand operators
  Rational operator+=(const Rational &secondRational);
  Rational operator-=(const Rational &secondRational);
  Rational operator*=(const Rational &secondRational);
  Rational operator/=(const Rational &secondRational);

  // Define function operator []
  long& operator[](const int &index);

  // Define function operators for prefix ++ and --
  Rational operator++();
  Rational operator--();

  // Define function operators for postfix ++ and --
  Rational operator++(int dummy);
  Rational operator--(int dummy);

  // Define function operators for unary + and -
  Rational operator+();
  Rational operator-();

  // Define the output and input operator
  friend ostream &operator<<(ostream &stream, const Rational &rational);
  friend istream &operator>>(istream &stream, Rational &rational);

  // Define function operator for conversion
  operator double();

private:
  long numerator;
  long denominator;
  static long gcd(long n, long d);
};

#endif
