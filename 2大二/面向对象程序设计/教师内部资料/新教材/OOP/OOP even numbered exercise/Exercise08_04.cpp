#include <iostream>
using namespace std;

/** The method for sorting the numbers */
void sortAndKeepIndex(int list[], int indexList[], int size) {
  int currentMax;
  int currentMaxIndex;

  // Initialize indexList
  for (int i = 0; i < size; i++)
    indexList[i] = i;

  for (int i = size - 1; i >= 1; i--) {
    // Find the maximum in the list[0..i]
    currentMax = list[i];
    currentMaxIndex = i;

    for (int j = i - 1; j >= 0; j--) {
      if (currentMax < list[j]) {
        currentMax = list[j];
        currentMaxIndex = j;
      }
    }

    // Swap list[i] with list[currentMaxIndex] if necessary;
    if (currentMaxIndex != i) {
      list[currentMaxIndex] = list[i];
      list[i] = currentMax;

      // Swap the index in indexList too
      int temp = indexList[i];
      indexList[i] = indexList[currentMaxIndex];
      indexList[currentMaxIndex] = temp;
    }
  }
}

int main()
{
  const int NUMBER_OF_WORKERS = 8;
    double workHours[NUMBER_OF_WORKERS][7] = {
      {2, 4, 3, 4, 5, 8, 8},
      {7, 3, 4, 3, 3, 4, 4},
      {3, 3, 4, 3, 3, 2, 2},
      {9, 3, 4, 7, 3, 4, 1},
      {3, 5, 4, 3, 6, 3, 8},
      {3, 4, 4, 6, 3, 4, 4},
      {3, 7, 4, 8, 3, 8, 4},
      {6, 3, 5, 9, 2, 7, 9}};

    // Create an array to store total weekly hours
    int weeklyHours[NUMBER_OF_WORKERS] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < NUMBER_OF_WORKERS; i++)
      for (int j = 0; j < 7; j++)
        weeklyHours[i] += workHours[i][j];

    int indexList[NUMBER_OF_WORKERS];

    // Sort weeklyHours
    sortAndKeepIndex(weeklyHours, indexList, NUMBER_OF_WORKERS);

    // Display result
    for (int i = NUMBER_OF_WORKERS - 1; i >= 0; i--)
      cout << "Employee " << indexList[i] << ": " <<
        weeklyHours[i] << endl;

return 0;
}

