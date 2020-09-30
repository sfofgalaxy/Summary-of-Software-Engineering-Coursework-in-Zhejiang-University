#include <iostream>
using namespace std;

void merge(const int list1[], int size1, const int list2[], int size2, 
  int list3[]);

int main()
{
  const int MAX_SIZE = 20;

  // Enter values for list1
  int list1[MAX_SIZE];
  cout << "Enter list1: ";
  int size1;
  cin >> size1;

  for (int i = 0; i < size1; i++)
    cin >> list1[i];

  // Enter values for list2
  cout << "Enter list2: ";
  int list2[MAX_SIZE];
  int size2;
  cin >> size2;

  for (int i = 0; i < size2; i++)
    cin >> list2[i];

  // Merger list1 with list2 into list3
  int list3[2 * MAX_SIZE];
  merge(list1, size1, list2, size2, list3);

  // Display list3
  for (int i = 0; i < size1 + size2; i++)
  {
    cout << list3[i] << " ";
  }

  return 0;
}

void merge(const int list1[], int list1Size,
  const int list2[], int list2Size, int temp[])
{
  int current1 = 0; // Current index in list1
  int current2 = 0; // Current index in list2
  int current3 = 0; // Current index in temp

  while (current1 < list1Size && current2 < list2Size)
  {
    if (list1[current1] < list2[current2])
      temp[current3++] = list1[current1++];
    else
      temp[current3++] = list2[current2++];
  }

  while (current1 < list1Size)
    temp[current3++] = list1[current1++];

  while (current2 < list2Size)
    temp[current3++] = list2[current2++];
}
