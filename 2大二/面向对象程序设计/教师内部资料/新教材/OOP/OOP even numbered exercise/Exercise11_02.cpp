#include <iostream>
using namespace std;

int main()
{
  // Prompt the user to enter array size
  cout << "Enter array size: ";
  int arraySize;
  cin >> arraySize;

  int* numbers = new int[arraySize];
  int size = 0;

  for (int i = 0; i < arraySize; i++) 
  {
    // Read and store numbers in an array if it is new
    cout << "Enter an integer: ";
    int value;
    cin >> value;

    bool isInArray = false;

    for (int j = 0; j < size; j++)
      if (*(numbers + j) == value) 
      {
        isInArray = true;
        break;
      }

    if (!isInArray) 
    {
      *(numbers + size) = value;
      size++;
    }
  }

  for (int i = 0; i < size; i++)
    cout << *(numbers + i) << " ";

  return 0;
}
