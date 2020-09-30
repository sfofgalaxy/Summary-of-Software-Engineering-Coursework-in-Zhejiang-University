#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int count = 1;
  for (int i = 100; i <= 1000; i++)
    if (i % 5 == 0 && i % 6 == 0)
      (count++ % 10 != 0) ? cout << setw(4) << i : cout << setw(4) << i << "\n";

  return 0;
}
