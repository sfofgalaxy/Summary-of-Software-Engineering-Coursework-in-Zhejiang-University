#include <iostream>
#include <ctime>
using namespace std;

int main()
{
  srand(time(0));
  double x = rand() * 100.0 / RAND_MAX - 50;
  double y = rand() * 200.0 / RAND_MAX- 100;

  cout << x << ", " << y << endl;

  return 0;
}