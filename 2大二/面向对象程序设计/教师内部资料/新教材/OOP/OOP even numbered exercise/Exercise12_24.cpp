#include <iostream>
#include <vector>
using namespace std;

double deltaA(vector<vector<double> > a)
{
  double result = a[0][0] * a[1][1] * a[2][2] +
    a[2][0] * a[0][1] * a[1][2] + a[0][2] * a[1][0] * a[2][1] -
    a[0][2] * a[1][1] * a[2][0] - a[0][0] * a[1][2] * a[2][1] -
    a[2][2] * a[1][0] * a[0][1];
  return result;
}

int main()
{
  vector<vector<double> > a(3);
  a[0] = vector<double>(3);
  a[1] = vector<double>(3);
  a[2] = vector<double>(3);

  cout << "Enter a11, a12, a13, a21, a22, a23, a31, a32, a33: ";
  cin >> a[0][0] >> a[0][1] >> a[0][2] >>
    a[1][0] >> a[1][1] >> a[1][2] >>
    a[2][0] >> a[2][1] >> a[2][2];

  cout << "Enter b1, b2, b3: ";
  double b1, b2, b3;
  cin >> b1 >> b2 >> b3;

  double delta = deltaA(a);
  if (delta == 0)
    cout << "No solution" << endl;
  else
  {
    double x = ((a[1][1] * a[2][2] - a[1][2] * a[2][1]) * b1 +
      (a[0][2] * a[2][1] - a[0][1] * a[2][2]) * b2 +
      (a[0][1] * a[1][2] - a[0][2] * a[1][1]) * b3) / delta;
    double y = ((a[1][2] * a[2][0] - a[1][0] * a[2][2]) * b1 +
      (a[0][0] * a[2][2] - a[0][2] * a[2][0]) * b2 +
      (a[0][2] * a[1][0] - a[0][0] * a[1][2]) * b3) / delta;
    double z = ((a[1][0] * a[2][1] - a[1][1] * a[2][0]) * b1 +
      (a[0][1] * a[2][0] - a[0][0] * a[2][1]) * b2 +
      (a[0][0] * a[1][1] - a[0][1] * a[1][0]) * b3) / delta;

    cout << "The solution is " << x << " " << y << " " << z << endl;
  }

  return 0;
}
