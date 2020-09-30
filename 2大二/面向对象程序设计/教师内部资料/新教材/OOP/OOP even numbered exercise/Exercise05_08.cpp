#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  cout << setw(14) << "RealNumber" << setw(14) << "SquareRoot" << endl;
  cout << "--------------------------------" << endl;

  for (int num = 0; num <= 20; num++)
  {
    cout << setw(14) << num << setw(14) << sqrt(num * 1.0) << endl;
  }

  return 0;
}
