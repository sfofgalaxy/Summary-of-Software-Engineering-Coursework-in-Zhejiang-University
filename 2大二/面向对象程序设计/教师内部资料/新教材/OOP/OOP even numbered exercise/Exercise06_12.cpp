#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double m(int n)
{
  double sum = 0;

  for (int i = 1; i <= n; i++)
    sum += i * 1.0 / (i + 1);

  return sum;
}

int main()
{
  cout << "i\t\tm(i)" << endl;
  for (int i = 1; i <= 20; i++)
    cout << i << "\t\t" << m(i) << endl;

  return 0;
}
