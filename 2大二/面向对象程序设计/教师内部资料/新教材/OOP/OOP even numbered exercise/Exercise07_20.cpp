#include <iostream>
#include <cstring>
using namespace std;

bool strictlyEqual(const int list1[], const int list2[], int size)
{
  for (int i = 0; i < size; i++)
    if (list1[i] != list2[i])
      return false;

  return true;
}

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

  if (size1 == size2 && strictlyEqual(list1, list2, size1))
  {
    cout << "\nTwo lists are strictly identical" << endl;
  }
  else
  {
    cout << "\nTwo lists are not strictly identical" << endl;
  }

  return 0;
}
