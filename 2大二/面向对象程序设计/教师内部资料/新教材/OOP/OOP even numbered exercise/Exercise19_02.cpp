#include <iostream>
using namespace std;

// Function prototype
template<typename T>
void arraycopy(T source[], int sourceStartIndex,
  T target[], int targetStartIndex, int length);

template<typename T>
void merge(T list1[], int list1Size,
  T list2[], int list2Size, T temp[]);

/* The function for sorting the numbers */
template<typename T>
void mergeSort(T list[], int arraySize)
{
  if (arraySize > 1)
  {
    // Merge sort the first half
    T *firstHalf = new T[arraySize / 2];
    arraycopy(list, 0, firstHalf, 0, arraySize / 2);
    mergeSort(firstHalf, arraySize / 2);

    // Merge sort the second half
    int secondHalfLength = arraySize - arraySize / 2;
    T *secondHalf = new T[secondHalfLength];
    arraycopy(list, arraySize / 2, secondHalf, 0, secondHalfLength);
    mergeSort(secondHalf, secondHalfLength);

    // Merge firstHalf with secondHalf
    T *temp = new T[arraySize];
    merge(firstHalf,  arraySize / 2, secondHalf, secondHalfLength,
      temp);
    arraycopy(temp, 0, list, 0, arraySize);
    delete [] temp;
    delete [] firstHalf;
    delete [] secondHalf;
  }
}

template<typename T>
void merge(T list1[], int list1Size,
  T list2[], int list2Size, T temp[])
{
  int current1 = 0; // Index in list1
  int current2 = 0; // Index in list2
  int current3 = 0; // Index in temp

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

template<typename T>
void arraycopy(T source[], int sourceStartIndex,
  T target[], int targetStartIndex, int length)
{
  for (int i = 0; i < length; i++)
  {
    target[i + targetStartIndex] = source[i + sourceStartIndex];
  }
}

template<typename T>
void printArray(T list[], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    cout << list[i] << " ";
  }
  cout << endl;
}

int main()
{
  int list1[] = {3, 5, 1, 0, 2, 8, 7};
  mergeSort(list1, 7);
  printArray(list1, 7);

  double list2[] = {3.5, 0.5, 1.4, 0.4, 2.5, 1.8, 4.7};
  mergeSort(list2, 7);
  printArray(list2, 7);

  string list3[] = {"Atlanta", "Denver", "Chicago", "Dallas"};
  mergeSort(list3, 4);
  printArray(list3, 4);

  return 0;
}

