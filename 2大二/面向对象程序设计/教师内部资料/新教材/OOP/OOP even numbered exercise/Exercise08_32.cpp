#include <iostream>
#include <cmath>
using namespace std;

const int SIZE = 2;

double getTriangleArea(const double points[][SIZE]);
double distance(double x1, double y1, double x2, double y2); 

int main()
{
  double points[3][SIZE];    
  cout << "Enter x1, y1, x2, y2, x3, y3: ";
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++) 
      cin >> points[i][j];

  double area = getTriangleArea(points);
        
  if (area == 0) 
    cout << "The three points are on the same line" << endl;
  else 
	cout << "The area of the triangle is " << area << endl;
  
  return 0;
}

double getTriangleArea(const double p[][SIZE])
{
  double s1 = distance(p[0][0],  p[0][1], p[1][0], p[1][1]);
  double s2 = distance(p[0][0],  p[0][1], p[2][0], p[2][1]);
  double s3 = distance(p[2][0],  p[2][1], p[1][0], p[1][1]);
  double s = (s1 + s2 + s3) / 2;
  double area = s * (s - s1) * (s - s2) * (s - s3);
    
  if (area < 0.0000000000001)
    return 0;
  else
    return sqrt(area);
}

double distance(double x1, double y1, double x2, double y2) 
{
  double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  return d;
}