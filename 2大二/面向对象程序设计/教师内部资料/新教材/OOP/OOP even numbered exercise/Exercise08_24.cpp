#include <iostream>
using namespace std;

void readASolution(int grid[][9]);
bool isValid(const int grid[][9]);
bool is1To9(const int list[]);
void selectionSort(int list[], int listSize);

int main()
{
  // Read a Sudoku puzzle
  int grid[9][9];
  readASolution(grid);

  cout << (isValid(grid) ? "Valid solution" : "Invalid solution");

  return 0;
}

/** Read a Sudoku puzzle from the keyboard */
void readASolution(int grid[][9])
{
  cout << "Enter a Sudoku puzzle:" << endl;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      cin >> grid[i][j];
}

// Check whether the fixed cells are valid in the grid 
bool isValid(const int grid[][9]) 
{
  // Check whether each row has numbers 1 to 9
  for (int i = 0; i < 9; i++)
    if (!is1To9(grid[i])) // If grid[i] does not contain 1 to 9
      return false;
    
  // Check whether each column has numbers 1 to 9
  for (int j = 0; j < 9; j++) {
    // Obtain a column in the one-dimensional array
    int column[9]; 
    for (int i = 0; i < 9; i++) {
      column[i] = grid[i][j];
    }
      
    if (!is1To9(column)) // If column does not contain 1 to 9
      return false;
  }
    
  // Check whether each 3 by 3 box has numbers 1 to 9
  for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        // The starting element in a small 3 by 3 box
        int k = 0;
        int list[9]; // Get all number in the box to list
        for (int row = i * 3; row < i * 3 + 3; row ++)
          for (int column = j * 3; column < j * 3 + 3; column++) 
            list[k++] = grid[row][column];
            
        if (!is1To9(list)) // If list does not contain 1 to 9
          return false;
      }
    }

  return true; // The fixed cells are valid
}
  
/** Check whether the one-dimensional array contains 1 to 9 */
bool is1To9(const int list[]) 
{
  // Make a copy of the array
  int temp[9];
  for (int i = 0; i < 9; i++)
	temp[i] = list[i];
  
  // Sort the array
  selectionSort(temp, 9);
    
  // Check if list contains 1, 2, 3, ..., 9
  for (int i = 0; i < 9; i++)
    if (temp[i] != i + 1)  
      return false;
    
  return true; // The list contains exactly 1 to 9
}

void selectionSort(int list[], int listSize)
{
  for (int i = 0; i < listSize; i++)
  {
    // Find the minimum in the list[i..listSize-1]
    int currentMin = list[i];
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