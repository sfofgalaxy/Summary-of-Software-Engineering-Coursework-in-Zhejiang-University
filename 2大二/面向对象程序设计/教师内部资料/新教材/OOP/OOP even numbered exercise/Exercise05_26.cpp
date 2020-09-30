#include <iostream>
using namespace std;

int main()
{
  double sum = 0;
  for (int i = 1; i <= 97; i += 2)
    sum += 1.0 * i / (i + 2);

  cout << "sum is " << sum;

  return 0;
}
