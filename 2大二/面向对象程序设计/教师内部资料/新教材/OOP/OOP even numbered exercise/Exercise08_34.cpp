#include <iostream>
#include <cmath>
using namespace std;

const int SIZE = 2;

void getRightmostLowestPoint(const double points[][SIZE],
  double numberOfPoints, double rightMostPoint[]);

int main()
{
  double p[6][2];    
  cout << "Enter 6 points: ";
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 2; j++)
      cin >> p[i][j];

  double rightMostPoint[2];

  getRightmostLowestPoint(p, 6, rightMostPoint);

  cout << "The rightmost lowest point is (" << 
    rightMostPoint[0] << ", " << rightMostPoint[1] << ")" << endl;

  return 0;
}

void getRightmostLowestPoint(const double p[][SIZE],
  double numberOfPoints, double rightMostPoint[])
{
  int rightMostIndex = 0;
  double rightMostX = p[0][0];
  double rightMostY = p[0][1];
    
  for (int i = 1; i < numberOfPoints; i++) 
  {
    if (rightMostY > p[i][1]) 
	{
      rightMostY = p[i][1];
      rightMostIndex = i;
    }
    else if (rightMostY == p[i][1] && rightMostX < p[i][0]) 
	{
      rightMostX = p[i][0];
      rightMostIndex = i;
    }
  }
  
  rightMostPoint[0] = p[rightMostIndex][0];
  rightMostPoint[1] = p[rightMostIndex][1];
}