#include <iostream>
#include <cmath>
using namespace std;

void solveQuadraticEquation(double a, double b, double c,
  double &discriminant, double &r1, double &r2)
{
  discriminant = b * b - 4 * a * c;

  if (discriminant >= 0)
  {
     r1 = (-b + sqrt(discriminant)) / (2 * a);
     r2 = (-b - sqrt(discriminant)) / (2 * a);
  }
}

int main()
{
  cout << "Enter a, b, c: ";
  double a, b, c, discriminant, r1, r2;
  cin >> a >> b >> c;

  solveQuadraticEquation(a, b, c, discriminant, r1, r2);

  cout << "Discriminant is " << discriminant << endl;

  if (discriminant > 0)
    cout << "Two roots are: " << r1 << " and " << r2 << endl;
  else if (discriminant == 0)
    cout << "The root is: " << r1 << endl;
  else
    cout << "The root has no roots " << endl;

  return 0;
}

