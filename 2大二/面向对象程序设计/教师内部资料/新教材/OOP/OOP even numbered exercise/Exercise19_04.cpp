#include <iostream>
using namespace std;

// Function prototypes
void quickSort(int list[], int arraySize);
void quickSort(int list[], int first, int last);
int partition(int list[], int first, int last);

void printArray(int list[], int first, int last)
{
  for (int i = first; i <= last; i++)
  {
    cout << list[i] <<  " ";
  }

  cout << endl;
}

void quickSort(int list[], int arraySize)
{
  quickSort(list, 0, arraySize - 1);
}

int findMedium(int list[], int first, int last)
{
  int middle = (first + last) / 2;

  if (list[first] <= list[middle] && list[middle] <= list[last])
    return middle;
  else if (list[first] <= list[last] && list[last] <= list[middle])
    return last;
  else if (list[middle] <= list[first] && list[first] <= list[last])
    return first;
  else if (list[middle] <= list[last] && list[last] <= list[first])
    return last;
  else if (list[last] <= list[first] && list[first] <= list[middle])
    return first;
  else // if (list[last] <= list[middle] && list[middle] <= list[first])
    return middle;
}

void quickSort(int list[], int first, int last)
{
  if (last > first)
  {
    // Find medium among first, middle, and last
    int medium = findMedium(list, first, last);

    // Swap the medium with the first
    if (first != medium)
    {
      int temp = list[medium];
      list[medium] = list[first];
      list[first] = temp;
    }

    int pivotIndex = partition(list, first, last);
    quickSort(list, first, pivotIndex - 1);
    quickSort(list, pivotIndex + 1, last);
  }
}

/* Partition the array list[first..last] */
int partition(int list[], int first, int last)
{
  int pivot = list[first]; // Choose the first element as the pivot
  int low = first + 1; // Index for forward search
  int high = last; // Index for backward search

  while (high > low)
  {
    // Search forward from left
    while (low <= high && list[low] <= pivot)
      low++;

    // Search backward from right
    while (low <= high && list[high] > pivot)
      high--;

    // Swap two elements in the list
    if (high > low)
    {
      int temp = list[high];
      list[high] = list[low];
      list[low] = temp;
    }
  }

  while (high > first && list[high] >= pivot)
    high--;

  // Swap pivot with list[high]
  if (pivot > list[high])
  {
    list[first] = list[high];
    list[high] = pivot;
    return high;
  }
  else
  {
    return first;
  }
}

int main()
{
  int list[] = {1, 9, 4, 6, 5, -4, -5};
  quickSort(list, 7);

  printArray(list, 0, 6);
  return 0;
}
