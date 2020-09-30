#include <iostream>
#include <cmath>
using namespace std;

int average(int array[], int size) {
  int sum = 0;
  for (int i = 0; i < size; i++)
    sum += array[i];
  return sum / size;
}

double average(double array[], int size) {
  double sum = 0;
  for (int i = 0; i < size; i++)
    sum += array[i];
  return sum / size;
}

int main()
{
  cout << "Enter ten double values: ";
  double list[10];
  for (int i = 0; i < 10; i++)
    cin >> list[i];

  cout << "Average is " << average(list, 10) << endl;

  return 0;
}
