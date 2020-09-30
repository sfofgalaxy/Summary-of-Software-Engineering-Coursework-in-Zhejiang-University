#ifndef RATIONALWITHOPERATORS_H
#define RATIONALWITHOPERATORS_H
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <iostream>
using namespace std;

class Rational
{
public:
  Rational();
  Rational(int numerator, int denominator);
  int getNumerator() const;
  int getDenominator() const;
  Rational add(const Rational& secondRational) const;
  Rational subtract(const Rational& secondRational) const;
  Rational multiply(const Rational& secondRational) const;
  Rational divide(const Rational& secondRational) const;
  int compareTo(const Rational& secondRational) const;
  bool equals(const Rational& secondRational) const;
  int intValue() const;
  double doubleValue() const;
  string toString() const;

  Rational(int numerator); // Suitable for type conversion 

  // Define function operators for augmented operators
  Rational& operator+=(const Rational& secondRational);
  Rational& operator-=(const Rational& secondRational);
  Rational& operator*=(const Rational& secondRational);
  Rational& operator/=(const Rational& secondRational);

  // Define function operator []
  int& operator[](int index);

  // Define function operators for prefix ++ and --
  Rational& operator++();
  Rational& operator--();

  // Define function operators for postfix ++ and --
  Rational operator++(int dummy);
  Rational operator--(int dummy);

  // Define function operators for unary + and -
  Rational operator+();
  Rational operator-();

  // Define the << and >> operators
  friend ostream& operator<<(ostream& , const Rational&);
  friend istream& operator>>(istream& , Rational&);

private:
  int numerator;
  int denominator;
  static int gcd(int n, int d);
};

// Define nonmember function operators for relational operators
bool operator<(const Rational& r1, const Rational& r2);
bool operator<=(const Rational& r1, const Rational& r2);
bool operator>(const Rational& r1, const Rational& r2);
bool operator>=(const Rational& r1, const Rational& r2);
bool operator==(const Rational& r1, const Rational& r2);
bool operator!=(const Rational& r1, const Rational& r2);

// Define nonmember function operators for arithmetic operators
Rational operator+(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);

#endif

#include <sstream>

Rational::Rational()
{
  numerator = 0;
  denominator = 1;
}

Rational::Rational(int numerator, int denominator)
{
  int factor = gcd(numerator, denominator);
  this->numerator = (denominator > 0 ? 1 : -1) * numerator / factor;
  this->denominator = abs(denominator) / factor;
}

int Rational::getNumerator() const
{
  return numerator;
}

int Rational::getDenominator() const
{
  return denominator;
}

// Find GCD of two numbers 
int Rational::gcd(int n, int d) 
{
  int n1 = abs(n);
  int n2 = abs(d);
  int gcd = 1;

  for (int k = 1; k <= n1 && k <= n2; k++)
  {
    if (n1 % k == 0 && n2 % k == 0)
      gcd = k;
  }

  return gcd;
}

Rational Rational::add(const Rational& secondRational) const
{
  int n = numerator * secondRational.getDenominator() +
    denominator * secondRational.getNumerator();
  int d = denominator * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::subtract(const Rational& secondRational) const
{
  int n = numerator * secondRational.getDenominator()
    - denominator * secondRational.getNumerator();
  int d = denominator * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::multiply(const Rational& secondRational) const
{
  int n = numerator * secondRational.getNumerator();
  int d = denominator * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::divide(const Rational& secondRational) const
{
  int n = numerator * secondRational.getDenominator();
  int d = denominator * secondRational.numerator;
  return Rational(n, d);
}

int Rational::compareTo(const Rational& secondRational) const
{
  Rational temp = subtract(secondRational);
  if (temp.getNumerator() < 0)
    return -1;
  else if (temp.getNumerator() == 0)
    return 0;
  else
    return 1;
}

bool Rational::equals(const Rational& secondRational) const
{
  if (compareTo(secondRational) == 0)
    return true;
  else
    return false;
}

int Rational::intValue() const
{
  return getNumerator() / getDenominator();
}

double Rational::doubleValue() const
{
  return 1.0 * getNumerator() / getDenominator();
}

string Rational::toString() const
{
  stringstream ss;
  ss << numerator;

  if (denominator > 1)
    ss << "/" << denominator;

  return ss.str();
}

Rational::Rational(int numerator) // Suitable for type conversion
{
  this->numerator = numerator;
  this->denominator = 1;
}

// Define function operators for augmented operators
Rational& Rational::operator+=(const Rational& secondRational)
{
  *this = add(secondRational);
  return *this;
}

Rational& Rational::operator-=(const Rational& secondRational)
{
  *this = subtract(secondRational);
  return *this;
}

Rational& Rational::operator*=(const Rational& secondRational)
{
  *this = multiply(secondRational);
  return *this;
}

Rational& Rational::operator/=(const Rational& secondRational)
{
  *this = divide(secondRational);
  return *this;
}

// Define function operator []
int& Rational::operator[](int index)
{
  if (index == 0)
    return numerator;
  else if (index == 1)
    return denominator;
  else 
    throw runtime_error("index out of range");
}

// Define function operators for prefix ++ and --
Rational& Rational::operator++()
{
  numerator += denominator;
  return *this;
}

Rational& Rational::operator--()
{
  numerator -= denominator;
  return *this;
}

// Define function operators for postfix ++ and --
Rational Rational::operator++(int dummy)
{
  Rational temp(numerator, denominator);
  numerator += denominator;
  return temp;
}

Rational Rational::operator--(int dummy)
{
  Rational temp(numerator, denominator);
  numerator -= denominator;
  return temp;
}

// Define function operators for unary + and -
Rational Rational::operator+()
{
  return *this;
}

Rational Rational::operator-()
{
  return Rational(-numerator, denominator);
}

// Define the output and input operator
ostream& operator<<(ostream& out, const Rational& rational)
{
  if (rational.denominator == 1)
    out << rational.numerator;
  else
    out << rational.numerator << "/" << rational.denominator;
  return out;
}

istream& operator>>(istream& in, Rational& rational)
{
  cout << "Enter numerator: ";
  in >> rational.numerator;

  cout << "Enter denominator: ";
  in >> rational.denominator;
  return in;
}

// Define function operators for relational operators
bool operator<(const Rational& r1, const Rational& r2)
{
  return (r1.compareTo(r2) < 0);
}

bool operator<=(const Rational& r1, const Rational& r2)
{
  return (r1.compareTo(r2) <= 0);
}

bool operator>(const Rational& r1, const Rational& r2)
{
  return (r1.compareTo(r2) > 0);
}

bool operator>=(const Rational& r1, const Rational& r2)
{
  return (r1.compareTo(r2) >= 0);
}

bool operator==(const Rational& r1, const Rational& r2)
{
  return (r1.compareTo(r2) == 0);
}

bool operator!=(const Rational& r1, const Rational& r2)
{
  return (r1.compareTo(r2) != 0);
}

// Define non-member function operators for arithmetic operators
Rational operator+(const Rational& r1, const Rational& r2)
{
  return r1.add(r2);
}

Rational operator-(const Rational& r1, const Rational& r2)
{
  return r1.subtract(r2);
}

Rational operator*(const Rational& r1, const Rational& r2)
{
  return r1.multiply(r2);
}

Rational operator/(const Rational& r1, const Rational& r2)
{
  return r1.divide(r2);
}

int main()
{
  // Create and initialize two rational numbers r1 and r2.
  Rational r1(4, 2);
  Rational r2(2, 3);

  // Test relational operators
  cout << r1 << " > " << r2 << " is " << 
    ((r1 > r2) ? "true" : "false") << endl;
  cout << r1 << " < " << r2 << " is " << 
    ((r1 < r2) ? "true" : "false") << endl;
  cout << r1 << " == " << r2 << " is " << 
    ((r1 == r2) ? "true" : "false") << endl;
  cout << r1 << " != " << r2 << " is " << 
    ((r1 != r2) ? "true" : "false") << endl;

  // Test toString, add, subtract, multiply, and divide operators
  cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;
  cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;
  cout << r1 << " * " << r2 << " = " << r1 * r2 << endl;
  cout << r1 << " / " << r2 << " = " << r1 / r2 << endl;

  // Test augmented operators
  Rational r3(1, 2);
  r3 += r1;
  cout << "r3 is " << r3 << endl;

  // Test function operator []
  Rational r4(1, 2);
  r4[0] = 3; r4[1] = 4;
  cout << "r4 is " << r4 << endl;

  // Test function operators for prefix ++ and --
  r3 = r4++;
  cout << "r3 is " << r3 << endl;
  cout << "r4 is " << r4 << endl;

  // Test function operator for conversion
  cout << "1 + " << r4 << " is " << (1 + r4) << endl;

  return 0;
}
