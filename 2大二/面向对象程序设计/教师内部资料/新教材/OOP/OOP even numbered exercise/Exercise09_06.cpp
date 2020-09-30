#include <iostream>
#include <cmath>
using namespace std;

class QuadraticEquation
{
private:
  int a;
  int b;
  int c;

public:
  QuadraticEquation(double a, double b, double c)
    : a(a), b(b), c(c)
  {
  }

  double getA()
  {
    return a;
  }

  double getB()
  {
    return b;
  }

  double getC()
  {
    return c;
  }

  double getDiscriminant()
  {
    return b * b - 4 * a * c;
  }

  double getRoot1()
  {
    if (getDiscriminant() < 0)
      return 0;
    else
    {
      return (-b + sqrt(getDiscriminant())) / (2 * a);
    }
  }

  double getRoot2()
  {
    if (getDiscriminant() < 0)
      return 0;
    else
    {
      return (-b - sqrt(getDiscriminant())) / (2 * a);
    }
  }
};

int main()
{
  cout << "Enter a, b, c: ";
  double a, b, c, discriminant, r1, r2;
  cin >> a >> b >> c;

  QuadraticEquation equation(a, b, c);
  discriminant = equation.getDiscriminant();

  if (discriminant < 0)
  {
    cout << "The equation has no roots" << endl;
  }
  else if (discriminant == 0)
  {
    cout << "The root is " << equation.getRoot1() << endl;
  }
  else // (discriminant >= 0)
  {
     cout << "The roots are " << equation.getRoot1() << " and "
       << equation.getRoot2() << endl;
  }

  return 0;
}
