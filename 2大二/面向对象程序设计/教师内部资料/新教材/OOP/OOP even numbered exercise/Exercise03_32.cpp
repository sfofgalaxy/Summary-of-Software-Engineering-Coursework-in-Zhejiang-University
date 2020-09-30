#include <iostream>
using namespace std;

int main()
{
  double x1, y1, x2, y2;
  cout << "Enter the coordinates for two points: ";
  cin >> x1 >> y1 >> x2 >> y2;
  
  double m = (y2 - y1) / (x2 - x1);
  double b = y1 - m * x1;

  cout << "The line equation for two points (" << x1 << ", "
    << y1 << ") and (" << x2 << ", " << y2 << ") is " <<
    "y = ";
  
  if (m == -1)
    cout << "-x";
  else if (m == 1)
    cout << "x";
  else 
    cout << m << "x";
  
  if (b > 0)
    cout << " + " << b << endl;
  else if (b < 0)
    cout << " " << b << endl;
  else // b is 0
    cout << endl;

  return 0;
}
