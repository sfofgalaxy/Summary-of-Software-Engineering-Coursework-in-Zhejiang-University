#include <iostream>
#include <cmath>
using namespace std;

class MyPoint
{
  private:
  double x;
  double y;

  public:
  MyPoint()
  {
    x = y = 0;
  }

  MyPoint(double x, double y)
  {
    this->x = x;
    this->y = y;
  }

  double distance(MyPoint p2)
  {
    return sqrt((x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y));
  }
};

int main()
{
  MyPoint p1(1, 2);
  MyPoint p2(4, 2.5);
  cout << p1.distance(p2) << endl;

  return 0;
}

