#include <iostream>
using namespace std;

int main()
{
  cout << "Enter v and a: ";
  double v, a;
  cin >> v >> a;

  double length = v * v / (2 * a);

  cout << "The minimum runway length for this airplane is " <<
        length << endl;

  return 0;
}
