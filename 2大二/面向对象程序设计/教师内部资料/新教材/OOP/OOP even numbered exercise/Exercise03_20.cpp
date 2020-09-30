#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  // Enter a point with two double values
  cout << "Enter a point with two coordinates: ";
  double x, y;
  cin >> x >> y;

  // Compute the horizontal distance to the center of the rectangle
  double hDistance = pow(x * x, 0.5);

  // Compute the vertical distance to the center of the rectangle
  double vDistance = pow(y * y, 0.5);

  if (hDistance <= 5 && vDistance <= 2.5)
    cout << "Point (" << x << ", " << y << ") is in the rectangle" << endl;
  else
    cout << "Point (" << x << ", " << y << ") is not in the rectangle" << endl;

  return 0;
}
