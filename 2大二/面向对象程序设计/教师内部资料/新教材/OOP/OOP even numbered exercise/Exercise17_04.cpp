#include <iostream>
using namespace std;

double m(int i)
{
  if (i == 1)
    return 1;
  else
    return m(i - 1) + 1.0 / i;
}

int main()
{
  for (int i = 1; i <= 10; i++)
    cout << m(i) << endl;

  return 0;
}
