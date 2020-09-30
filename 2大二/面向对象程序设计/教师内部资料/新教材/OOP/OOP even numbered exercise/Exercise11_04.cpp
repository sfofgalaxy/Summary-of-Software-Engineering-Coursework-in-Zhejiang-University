#include <iostream>
using namespace std;

int average(const int* array, int size)
{
  int total = 0;
  for (int i = 0; i < size; i++)
    total += *(array + i);
  return total / size;
}

double average(const double* array, int size)
{
  int total = 0;
  for (int i = 0; i < size; i++)
    total += *(array + i);
  return total / size;
}

int main()
{
  const int SIZE = 10;
  double list2[SIZE];

  cout << "Enter ten numbers: ";
  for (int i = 0; i < SIZE; i++)
    cin >> list2[i];

  cout << "list2's total is " << average(list2, SIZE) << endl;

  return 0;
}
