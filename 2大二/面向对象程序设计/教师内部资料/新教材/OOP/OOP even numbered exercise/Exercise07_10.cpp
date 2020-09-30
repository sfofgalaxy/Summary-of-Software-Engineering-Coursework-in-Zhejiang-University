#include <iostream>
#include <cmath>
using namespace std;

const int SIZE = 10;

int minIndex(double list[], int size)
{
  double min = list[0];
  int minIndex = 0;

  for (int i = 1; i < size; i++)
    if (min > list[i])
    {
      min = list[i];
      minIndex = i;
    }

  return minIndex;
}

int main()
{
  double list[SIZE];
  cout << "Enter ten numbers: ";
  for (int i = 0; i < SIZE; i++)
    cin >> list[i];


  cout << "The index of the min is " << minIndex(list, SIZE) << endl;

  return 0;
}
