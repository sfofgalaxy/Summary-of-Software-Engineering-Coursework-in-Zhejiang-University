#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  cout << "Enter the number of sides: ";
  int n;
  cin >> n;

  cout << "Enter the radius of the bounding circle: ";
  double radius;
  cin >> radius;

  const double PI = 3.14159;
  double angle = 0;
  
  cout << "The coordinates of the points on the polygon are " << endl;
  for (int i = 0; i < n; i++)
  {
    double x = radius * cos(angle);
    double y = radius * sin(angle);
    cout << "(" << x << ", " << y << ")" << endl;
    angle += 2 * PI / n;
  }

  return 0;
}