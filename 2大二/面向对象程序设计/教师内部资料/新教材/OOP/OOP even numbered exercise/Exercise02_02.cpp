#include <iostream>
using namespace std;

int main()
{
  cout << "Enter the radius and length of a cylinder: ";
  double radius, length;
  cin >> radius >> length;

  double area = radius * radius * 3.14159;
  double volume = area * length;

  cout << "The area is " << area << endl;
  cout << "The volume is " << volume << endl;

  return 0;
}
