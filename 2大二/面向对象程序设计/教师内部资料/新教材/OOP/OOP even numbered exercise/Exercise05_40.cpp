#include <iostream>
using namespace std;

int main()
{
  int headCount = 0;
  int tailCount = 0;
  srand(time(0));

  for (int i = 0; i < 100000; i++)
  {
    int number = rand() % 2;

    if (number == 0)
      headCount++;
    else
      tailCount++;
  }

  cout << "head count: " << headCount << endl;
  cout << "tail count: " << tailCount << endl;

  return 0;
}
