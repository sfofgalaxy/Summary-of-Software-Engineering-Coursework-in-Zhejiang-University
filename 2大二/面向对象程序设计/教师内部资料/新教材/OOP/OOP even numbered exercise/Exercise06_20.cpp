#include <iostream>
#include <cmath>
using namespace std;

/** Return true if point (x2, y2) is on the left side of the 
 *  directed line from (x0, y0) to (x1, y1) */ 
bool leftOfTheLine(double x0, double y0, 
  double x1, double y1, double x2, double y2);

/** Return true if point (x2, y2) is on the same  
 *  line from (x0, y0) to (x1, y1) */ 
bool onTheSameLine(double x0, double y0, 
  double x1, double y1, double x2, double y2);

/** Return true if point (x2, y2) is on the
 *  line segment from (x0, y0) to (x1, y1) */ 
bool onTheLineSegment(double x0, double y0, 
  double x1, double y1, double x2, double y2);

int main()
{
  double x0, y0, x1, y1, x2, y2;
  cout << "Enter three points for p0, p1, and p2: ";
  cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

  if (leftOfTheLine(x0, y0, x1, y1, x2, y2)) 
    cout << "(" << x2 << ", " << y2 << ") is on the left side of the line from"
      << " (" << x0 << ", " << y0 << ") to " << "(" << x1 << ", " << y1 << ")" << endl;   
  else if (onTheLineSegment(x0, y0, x1, y1, x2, y2)) 
    cout << "(" << x2 << ", " << y2 << ") is on the line segment from"
      << " (" << x0 << ", " << y0 << ") to " << "(" << x1 << ", " << y1 << ")" << endl;      
  else if (onTheSameLine(x0, y0, x1, y1, x2, y2)) 
    cout << "(" << x2 << ", " << y2 << ") is on the same line from"
      << " (" << x0 << ", " << y0 << ") to " << "(" << x1 << ", " << y1 << ")" << endl;      
  else
    cout << "(" << x2 << ", " << y2 << ") is on the right side of the line from"
      << " (" << x0 << ", " << y0 << ") to " << "(" << x1 << ", " << y1 << ")" << endl;  

  return 0;
}

/** Return true if point (x2, y2) is on the left side of the 
 *  directed line from (x0, y0) to (x1, y1) */ 
bool leftOfTheLine(double x0, double y0, 
  double x1, double y1, double x2, double y2)
{
  return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0) > 0;
}

/** Return true if point (x2, y2) is on the same  
 *  line from (x0, y0) to (x1, y1) */ 
bool onTheSameLine(double x0, double y0, 
  double x1, double y1, double x2, double y2)
{    
  return abs((x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0)) < 0.000000001;
}

/** Return true if point (x2, y2) is on the
 *  line segment from (x0, y0) to (x1, y1) */ 
bool onTheLineSegment(double x0, double y0, 
  double x1, double y1, double x2, double y2)
{
  double status = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
  return (abs(status) <= 0.00000000001 && ((x0 <= x2 && x2 <= x1) || (x0 >= x2 && x2 >= x1)));
}
