#include <iostream>
using namespace std;

int main()
{
  cout << "Enter the coordinates for two points: ";
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  
  cout << "The slope for the line that connects two points (" << x1 << ", " 
    << y1 << ") and (" << x2 << ", " << y2 << ") is " <<
    (y2 - y1) / (x2 - x1) << endl;

  return 0;
}
