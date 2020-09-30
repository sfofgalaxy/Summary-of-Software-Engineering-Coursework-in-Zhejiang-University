#include <iostream>
using namespace std;

/** The method for printing numbers */
void printList(double list[], int size)
{
  for (int i = 0; i < size; i++)
    cout << list[i] << "  ";
  cout << endl;
}

/** The method for sorting the numbers */
void selectionSort(double list[], int size)
{
  double currentMax;
  int currentMaxIndex;

  for (int i = size - 1; i >= 1; i--)
  {
    // Find the largest in the list[0..i]
    currentMax = list[0];
    currentMaxIndex = 0;

    for (int j = 1; j <= i; j++)
    {
      if (currentMax < list[j])
      {
        currentMax = list[j];
        currentMaxIndex = j;
      }
    }

    // Swap list[i] with list[currentMinIndex] if necessary;
    if (currentMaxIndex != i)
    {
      list[currentMaxIndex] = list[i];
      list[i] = currentMax;
    }
  }
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
  selectionSort(myList, SIZE);

  // Print the sorted list
  cout << "\nMy list after sort is: " << endl;
  printList(myList, SIZE);

  return 0;
}
