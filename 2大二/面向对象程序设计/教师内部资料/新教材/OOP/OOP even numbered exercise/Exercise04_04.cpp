#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  // Enter the side of the hexagon
  cout << "Enter the side: ";
  double side;
  cin >> side;

  // Compute the area
  double area = 6 * side * side / tan(3.14159 / 6) / 4;

  cout << "The area of the hexagon is " << area << endl;

  return 0;
}
