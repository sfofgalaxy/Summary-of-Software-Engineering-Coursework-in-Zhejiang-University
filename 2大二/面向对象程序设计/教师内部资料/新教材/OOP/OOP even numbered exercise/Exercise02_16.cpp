#include <iostream>
using namespace std;

int main()
{
  double side;
  // Enter the side of the hexagon
  cout << "Enter the side: ";
  cin >> side;

  // Compute the area
  double area = 3 * 1.732 * side * side / 2;

  cout << "The area of the hexagon is " << area;

  return 0;
}
