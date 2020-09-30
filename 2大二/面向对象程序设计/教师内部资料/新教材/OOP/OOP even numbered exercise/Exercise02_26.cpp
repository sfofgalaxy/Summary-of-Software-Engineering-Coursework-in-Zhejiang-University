#include <iostream>
using namespace std;

int main()
{
  double f, m, a;
  cout << "Enter the friction force in Newtons: ";
  cin >> f;
  cout << "Enter the object’s mass in kg: ";
  cin >> m;
  cout << "Enter the object’s acceleration in m/s^2: ";
  cin >> a;
  const double g = 9.8;
  double u = (f - m * a) / (m * g);
  cout << "The coefficient for friction is " << u << endl;

  return 0;
}
