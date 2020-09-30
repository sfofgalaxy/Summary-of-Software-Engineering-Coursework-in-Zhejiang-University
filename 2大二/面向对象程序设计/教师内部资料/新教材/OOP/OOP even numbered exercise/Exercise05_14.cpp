#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int i = 1;

  while (i * i <= 12000)
  {
    i++;
  }

  cout << "This number is " << i;

  return 0;
}
