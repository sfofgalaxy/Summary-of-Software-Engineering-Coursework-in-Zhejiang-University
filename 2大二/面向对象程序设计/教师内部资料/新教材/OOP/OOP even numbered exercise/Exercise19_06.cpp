#include <iostream>
using namespace std;

// T is a generic type
template<typename T>
bool ordered(T list[], int size);

// T is a generic type
template<typename T>
bool ordered(T list[], int size, bool ascending);

template<typename T>
bool ordered(T list[], int size)
{
  bool ordered = true;
  for (int i = 0; i < size - 1; i++)
    if (list[i] > list[i + 1]) {
      ordered = false;
      break;
    }

  return ordered;
}

// T is a generic type
template<typename T>
bool ordered(T list[], int size, bool ascending)
{
  if (ascending)
    return ordered(list, size);

  bool ordered = true;
  for (int i = 0; i < size - 1; i++)
    if (list[i] < list[i + 1]) {
      ordered = false;
      break;
    }

  return ordered;
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
  cout << ordered(list1, 7) << endl;
  cout << ordered(list1, 7, true) << endl;

  int list2[] = {1, 2, 3, 5, 7, 8};
  cout << ordered(list2, 6) << endl;
  cout << ordered(list2, 6, true) << endl;
  cout << ordered(list2, 6, false) << endl;

  return 0;
}
