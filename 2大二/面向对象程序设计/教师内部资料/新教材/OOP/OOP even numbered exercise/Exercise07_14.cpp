#include <iostream>
#include "LinearSearch.h"
#include "BinarySearch.h"
#include "SelectionSort.h"
using namespace std;

/** The method for printing numbers */
void printList(double list[], int size)
{
  for (int i = 0; i < size; i++)
    cout << list[i] << "  ";
  cout << endl;
}

void bubbleSort(double list[], int size)
{
  bool changed = true;
  do
  {
    changed = false;
    for (int j = 0; j < size - 1; j++)
      if (list[j] > list[j + 1])
      {
        //swap list[j] wiht list[j+1]
        double temp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = temp;
        changed = true;
      }
  }
  while (changed);
}

int main()
{
  const int SIZE = 10;
  double myList[SIZE];
  cout << "Enter ten numbers: ";
  for (int i = 0; i < SIZE; i++)
    cin >> myList[i];

  // Print the original list
  cout << "My list before sort is: ";
  printList(myList, SIZE);

  // Sort the list
  bubbleSort(myList, SIZE);

  // Print the sorted list
  cout << "\nMy list after sort is: " << endl;
  printList(myList, SIZE);

  return 0;
}
