#include <iostream>
using namespace std;

const int SIZE = 3;

void sortRows(const double m[][SIZE], double result[][SIZE]);
void selectionSort(double list[], int listSize);

int main()
{
  cout << "Enter a 3 by 3 matrix row by row: ";
  double m[SIZE][SIZE];
    
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      cin >> m[i][j];

  double result[SIZE][SIZE];
  sortRows(m, result);

  cout << "Result is: " << endl;
  for (int i = 0; i < SIZE; i++) 
  {
    for (int j = 0; j < SIZE; j++)
      cout << result[i][j] << " ";
    cout << endl;
  }

  return 0;
}

void sortRows(const double m[][SIZE], double result[][SIZE])
{
  double temp[SIZE];

  // Copy from m to result
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
      temp[j] = m[i][j];

    selectionSort(temp, SIZE);

	for (int j = 0; j < SIZE; j++)
	  result[i][j] = temp[j];
  }
} 


void selectionSort(double list[], int listSize)
{
  for (int i = 0; i < listSize; i++)
  {
    // Find the minimum in the list[i..listSize-1]
    double currentMin = list[i];
    int currentMinIndex = i;

    for (int j = i + 1; j < listSize; j++)
    {
      if (currentMin > list[j])
      {
        currentMin = list[j];
        currentMinIndex = j;
      }
    }

    // Swap list[i] with list[currentMinIndex] if necessary;
    if (currentMinIndex != i)
    {
      list[currentMinIndex] = list[i];
      list[i] = currentMin;
    }
  }
}