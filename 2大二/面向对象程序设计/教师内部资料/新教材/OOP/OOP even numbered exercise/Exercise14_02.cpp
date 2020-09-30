#include <iostream>
#include <string>
using namespace std;

class Rational
{
public:
  Rational();
  Rational(long numerator, long denominator);
  long getNumerator() const;
  long getDenominator() const;
  Rational add(const Rational& secondRational) const;
  Rational subtract(const Rational& secondRational) const;
  Rational multiply(const Rational& secondRational) const;
  Rational divide(const Rational& secondRational) const;
  int compareTo(const Rational& secondRational) const;
  bool equals(const Rational& secondRational) const;
  int intValue() const;
  double doubleValue() const;
  string toString() const;

private:
  long r[2];
  static long gcd(long n, long d);
};

Rational::Rational()
{
  r[0] = 0;
  r[1] = 1;
}

Rational::Rational(long numerator, long denominator)
{
  long factor = gcd(numerator, denominator);
  r[0] = ((denominator > 0) ? 1 : -1) * numerator / factor;
  r[1] = abs(denominator) / factor;
}

long Rational::getNumerator() const
{
  return r[0];
}

long Rational::getDenominator() const
{
  return r[1];
}

/** Find GCD of two numbers */
long Rational::gcd(long n, long d)
{
  long n1 = abs(n);
  long n2 = abs(d);
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
  long n = r[0] * secondRational.getDenominator() + r[1] * secondRational.getNumerator();
  long d = r[1] * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::subtract(const Rational & secondRational) const
{
  long n = r[0] * secondRational.getDenominator() - r[1] * secondRational.getNumerator();
  long d = r[1] * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::multiply(const Rational & secondRational) const
{
  long n = r[0] * secondRational.getNumerator();
  long d = r[1] * secondRational.getDenominator();
  return Rational(n, d);
}

Rational Rational::divide(const Rational & secondRational) const
{
  long n = r[0] * secondRational.getDenominator();
  long d = r[1] * secondRational.r[0];
  return Rational(n, d);
}

int Rational::compareTo(const Rational & secondRational) const
{
  Rational temp = this->subtract(secondRational);
  if (temp.getNumerator() < 0)
    return -1;
  else if (temp.getNumerator() == 0)
    return 0;
  else
    return 1;
}

bool Rational::equals(const Rational & secondRational) const
{
  if (this->compareTo(secondRational) == 0)
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
  char s1[20], s2[20];
  itoa(r[0], s1, 10); // Convert int to string s1
  itoa(r[1], s2, 10); // Convert int to string s2

  if (r[1] == 1)
    return string(s1);
  else
    return string(strcat(strcat(s1, "/"), s2));
}

int main()
{
  // Create and initialize two rational numbers r1 and r2.
  Rational r1(4, 2);
  Rational r2(2, 3);

  // Test toString, add, substract, multiply, and divide
  cout << r1.toString() << " + " << r2.toString() << " = "
    << r1.add(r2).toString() << endl;
  cout << r1.toString() << " - " << r2.toString() << " = "
    << r1.subtract(r2).toString() << endl;
  cout << r1.toString() << " * " << r2.toString() << " = "
    << r1.multiply(r2).toString() << endl;
  cout << r1.toString() << " / " << r2.toString() << " = "
    << r1.divide(r2).toString() << endl;

  // Test intValue and double
  cout << "r2.intValue()" << " is " << r2.intValue() << endl;
  cout << "r2.doubleValue()" << " is " << r2.doubleValue() << endl;

  // Test compareTo and equal
  cout << "r1.compareTo(r2) is " << r1.compareTo(r2) << endl;
  cout << "r2.compareTo(r1) is " << r2.compareTo(r1) << endl;
  cout << "r1.compareTo(r1) is " << r1.compareTo(r1) << endl;
  cout << "r1.equals(r1) is " << r1.equals(r1) << endl;
  cout << "r1.equals(r2) is " << r1.equals(r2) << endl;

  return 0;
}
