#include <iostream>
#include <string>
using namespace std;

template <typename T>
int linearSearch(T list[], int key, int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    if (key == list[i])
      return i;
  }

  return -1;
}

int main()
{
  int intArray[] =
  {
    1, 2, 3, 4, 8, 15, 23, 31
  };
  cout << "linearSearch(intArray, 3, 8) is " << linearSearch(intArray, 3, 8) << endl;
  cout << "linearSearch(intArray, 10, 8) is " << linearSearch(intArray, 10, 8) << endl;

  return 0;
}
