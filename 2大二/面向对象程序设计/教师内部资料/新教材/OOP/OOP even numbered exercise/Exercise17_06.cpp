#include <iostream>
using namespace std;

double m(int i)
{
  if (i == 1)
    return 1.0 / 2;
  else
    return m(i - 1) + i * 1.0 / (i + 1);
}

int main()
{
  for (int i = 1; i <= 10; i++)
    cout << "m(" << i << "): " << m(i) << endl;

  return 0;
}
