#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
  srand(time(0));

  double r = 40;
  const double PI = 3.14159;

  cout << "Three random points are" <<endl;
  int angle = rand() % 360;
  double x = r * cos(angle * PI / 180);
  double y = r * sin(angle * PI / 180);
  cout << "(" << x << ", " << y << ")" << endl;

  angle = rand() % 360;
  x = r * cos(angle * PI / 180);
  y = r * sin(angle * PI / 180);
  cout << "(" << x << ", " << y << ")" << endl;

  angle = rand() % 360;
  x = r * cos(angle * PI / 180);
  y = r * sin(angle * PI / 180);
  cout << "(" << x << ", " << y << ")" << endl;
  
  return 0;
}