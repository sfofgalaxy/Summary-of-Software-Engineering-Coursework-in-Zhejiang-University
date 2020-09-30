#include <iostream>
#include "LinearSearch.h"
#include "BinarySearch.h"
#include "SelectionSort.h"
using namespace std;

int main()
{
  int list[100000];
  for (int i = 0; i < 100000; i++)
  {
    list[i] = rand();
  }

  int key = rand();
  long startTime = time(0);

  cout << linearSearch(list, key, 100000) << endl;

  long endTime = time(0);

  cout << "End time: " << endTime << endl;
  cout << "Start time: " << startTime << endl;

  long executionTime = endTime - startTime;
  cout << "Execution time for linear search is " << executionTime << endl;

  selectionSort(list, 100000);

  startTime = time(0);
  cout << binarySearch(list, key, 100000) << endl;
  endTime = time(0);
  executionTime = endTime - startTime;
  cout << "Execution time for binary search is " << executionTime << endl;

  return 0;
}
