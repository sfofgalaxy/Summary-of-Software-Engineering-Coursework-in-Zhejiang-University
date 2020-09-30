#include <iostream>
using namespace std;

int main()
{
  const double DBL_EPSILON = 0.1e-15;

  double x1, y1, x2, y2, x3, y3, x4, y4;
  cout << "Enter x1, y1, x2, y2, x3, y3, x4, y4: ";
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  
  double a = (y1 - y2);
  double b = -(x1 - x2);
  double c = (y3 - y4);
  double d = -(x3 - x4);
  double e = (y1 - y2) * x1 - (x1 -x2) * y1;
  double f = (y3 - y4) * x3 - (x3 -x4) * y3;

  double detA = a * d - b * c;
    
  if (abs(detA) <= DBL_EPSILON) 
  {
    cout << "The two lines are parallel" << endl;
  }
  else 
  {
    double x = (e * d - b * f) / detA;
    double y = (a * f - e * c) / detA;
    cout << "The intersecting point is at (" << 
      x << ", " <<  y << ")" << endl;
  }
  
  return 0;
}