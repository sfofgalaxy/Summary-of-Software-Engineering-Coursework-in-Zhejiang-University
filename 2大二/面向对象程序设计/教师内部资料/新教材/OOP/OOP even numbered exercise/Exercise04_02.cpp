#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double x1, x2, y1, y2;
  cout << "Enter point 1 (latitude and longitude) in degrees: ";
  cin >> x1 >> y1;
  
  cout << "Enter point 2 (latitude and lantitude) in degrees: ";
  cin >> x2 >> y2;

  // Convert degrees to radians
  x1 = x1 * (3.14159 / 180);
  y1 = y1 * (3.14159 / 180);
  x2 = x2 * (3.14159 / 180);
  y2 = y2 * (3.14159 / 180);

  double d = 6371.01 * acos(sin(x1) * sin(x2) +
    cos(x1) * cos(x2) * cos(y1 - y2));

  cout << "The distance between the two points is " 
	<< d << " km" << endl;

  return 0;
}
