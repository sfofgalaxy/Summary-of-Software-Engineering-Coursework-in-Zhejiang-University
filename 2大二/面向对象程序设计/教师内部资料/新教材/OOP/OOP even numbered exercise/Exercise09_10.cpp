#include <iostream>
using namespace std;

class LinearEquation
{
public:
  LinearEquation(double newA, double newB, double newC,
      double newD, double newE, double newF);
  double getA();
  double getB();
  double getC();
  double getD();
  double getE();
  double getF();
  bool isSolvable();
  double getX();
  double getY();

private:
  double a, b, c, d, e, f;
};

LinearEquation::LinearEquation(double newA, double newB, double newC,
      double newD, double newE, double newF)
{
  a = newA;
  b = newB;
  c = newC; 
  d = newD;
  e = newE;
  f = newF; 
}

double LinearEquation::getA()
{
  return a;
}

double LinearEquation::getB() 
{
  return b;
}

double LinearEquation::getC()
{
  return c;
}

double LinearEquation::getD() 
{
  return d;
}

double LinearEquation::getE() 
{
  return e;
}

double LinearEquation::getF()
{
  return f;
}

bool LinearEquation::isSolvable()
{
  return a * d - b * c != 0;
}

double LinearEquation::getX() 
{
  double x = (e * d - b * f) / (a * d - b * c);
  return x; 
}

double LinearEquation::getY() 
{
  double y = (a * f - e * c) / (a * d - b * c);
  return y;
}

int main() {
  double x1, y1, x2, y2, x3, y3, x4, y4;

  cout << "Enter the endpoints of the first line segment: ";
  cin >> x1 >> y1 >> x2 >> y2;

  cout << "Enter the endpoints of the second line segment: ";
  cin >> x3 >> y3 >> x4 >> y4;
    

  // Build a 2 by 2 linear equation
  double a = (y1 - y2);
  double b = (-x1 + x2);
  double c = (y3 - y4);
  double d = (-x3 + x4);
  double e = -y1 * (x1 - x2) + (y1 - y2) * x1;
  double f = -y3 * (x3 - x4) + (y3 - y4) * x3;

  LinearEquation equation(a, b, c, d, e, f);

  if (equation.isSolvable()) 
  {
    cout << "The intersecting point is: (" <<
      equation.getX() << ", " << equation.getY() << ")" << endl;
  }
  else 
  {
    cout << "The two lines do not cross " << endl;
  }

  return 0;
}