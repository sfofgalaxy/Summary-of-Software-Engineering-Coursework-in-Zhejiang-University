#include <iostream>
#include <cmath>
#include "Complex.h"
using namespace std;

int main()
{
  cout << "Enter a, b, c: ";
  double a, b, c, discriminant, r1, r2;
  cin >> a >> b >> c;

  discriminant = b * b - 4 * a * c;

  if (discriminant < 0)
  {
    Complex r1(-b / (2 * a), sqrt(-discriminant) / (2 * a));
    Complex r2(-b / (2 * a), sqrt(-discriminant) / (2 * a));    
    cout << "The roots are " << r1 << " and " << r2 << endl;
  }
  else if (discriminant == 0)
  {
    r1 = (-b + pow(discriminant, 0.5)) / (2 * a);
    cout << "The root is " << r1 << endl;
  }
  else // (discriminant >= 0)
  {
     r1 = (-b + pow(discriminant, 0.5)) / (2 * a);
     r2 = (-b - pow(discriminant, 0.5)) / (2 * a);
     cout << "The roots are " << r1 << " and " << r2 << endl;
  }

  return 0;
}

