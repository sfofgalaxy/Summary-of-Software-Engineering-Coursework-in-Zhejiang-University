#include <iostream>
#include <cmath>
using namespace std;

class Circle2D
{
private:
  double x, y;
  double radius;

public:
  Circle2D()
  {
    x = 0;
    y = 0;
    radius = 1;
  }

  Circle2D(double x, double y, double radius)
  {
    this->x = x;
    this->y = y;
    this->radius = radius;
  }

  double getX() const
  {
    return x;
  }

  void setX(double x)
  {
    this->x = x;
  }

  double getY() const
  {
    return y;
  }

  void setY(double y)
  {
    this->y = y;
  }

  double getRadius() const
  {
    return radius;
  }

  void setRadius(double radius)
  {
    this->radius = radius;
  }

  double getPerimeter() const
  {
    return 2 * radius * 3.14159;
  }

  double getArea() const
  {
    return radius * radius * 3.14159;
  }

  bool contains(double x, double y) const
  {
    // MyPoint is defined in Exercise9_4
    return (abs(x - this->x) <= radius) && (abs(y - this->y) <= radius);
  }

  bool contains(const Circle2D &circle) const
  {
    return contains(circle.x - circle.radius, circle.y) && contains(circle.x + circle.radius, circle.y)
         && contains(circle.x, circle.y - circle.radius) && contains(circle.x, circle.y + circle.radius);
  }

  bool overlaps(const Circle2D &circle) const
  {
    // Two circles overlap if the distance between the two centers
    // are less than or equal to r1 + r2
    // MyPoint is defined in Exercise9_4
    return distance(x, y, circle.x, circle.y) <= radius + circle.radius;
  }

  static double distance(double x1, double y1, double x2, double y2)
  {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  }
};

int main()
{
  Circle2D c1(2, 2, 5.5);
  cout << "Area: " << c1.getArea() << endl;
  cout << "Perimeter: " << c1.getPerimeter() << endl;

  cout << c1.contains(3, 3) << endl;

  Circle2D c2(4, 5, 10.5);
  cout << c1.contains(c2) << endl;
  cout << c1.overlaps(c2) << endl;

  return 0;
}
