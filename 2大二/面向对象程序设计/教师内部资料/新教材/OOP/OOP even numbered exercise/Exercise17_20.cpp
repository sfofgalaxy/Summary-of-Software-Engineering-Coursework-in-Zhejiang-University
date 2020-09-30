/* This program finds all possible solutions */
#include <iostream>
using namespace std;

/*
int grid[9][9] = {  // Hold Sudoku puzzle, one solution sample
{0, 6, 0, 1, 0, 4, 0, 5, 0},
{0, 0, 8, 3, 0, 5, 6, 0, 0},
{2, 0, 0, 0, 0, 0, 0, 0, 1},
{8, 0, 0, 4, 0, 7, 0, 0, 6},
{0, 0, 6, 0, 0, 0, 3, 0, 0},
{7, 0, 0, 9, 0, 1, 0, 0, 4},
{5, 0, 0, 0, 0, 0, 0, 0, 2},
{0, 0, 7, 2, 0, 6, 9, 0, 0},
{0, 4, 0, 5, 0, 8, 0, 7, 0}};
*/

int grid[9][9] = {  // Hold Sudoku puzzle, five solution sample
{0, 0, 0, 1, 0, 0, 0, 0, 0},
{0, 0, 8, 3, 0, 5, 6, 0, 0},
{2, 0, 0, 0, 0, 0, 0, 0, 1},
{8, 0, 0, 4, 0, 7, 0, 0, 6},
{0, 0, 6, 0, 0, 0, 3, 0, 0},
{7, 0, 0, 9, 0, 1, 0, 0, 4},
{5, 0, 0, 0, 0, 0, 0, 0, 2},
{0, 0, 7, 2, 0, 6, 9, 0, 0},
{0, 4, 0, 5, 0, 8, 0, 7, 0}};

bool isFree[9][9]; // isFree[i][j] is true if (i, j) needs to be filled

void readAPuzzle();
bool isValid(int i, int j);
void printResult();
bool search(int row, int column);
void findFreeCells();

/** Read a Sudoku puzzle from the keyboard */
void readAPuzzle()
{
  // Create a Scanner
  cout << "Enter a Sudoku puzzle:" << endl;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      cin >> grid[i] [j];
}

/** Check whether grid[i][j] is valid in the grid */
bool isValid(int i, int j)
{
  // Check whether grid[i][j] is valid at the i's row
  for (int column = 0; column < 9; column++)
    if (column != j && grid[i][column] == grid[i][j])
      return false;

  // Check whether grid[i][j] is valid at the j's column
  for (int row = 0; row < 9; row++)
    if (row != i && grid[row] [j] == grid[i][j])
      return false;

  // Check whether grid[i][j] is valid in the 3 by 3 box
  for (int row = (i / 3) * 3; row < (i / 3) * 3 + 3; row++)
    for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; col++)
      if (row != i && col != j && grid[row] [col] == grid[i] [j])
        return false;

  return true; // The current value at grid[i][j] is valid
}

int c = 0; // Count the number of the solutions

void printResult()
{
  cout << "Solution " << ++c << ":" << endl;
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
      cout << " " << grid[i] [j] << " ";
    cout << endl;
  }
}

bool search(int row, int column)
{
  static bool found = false; // Set true when one solution is found

  if (!isFree[row] [column])
  {
    // Fill in the next cell
    if (column < 9 - 1)
      search(row, column + 1);
    else if (row < 9 - 1)
      search(row + 1, 0);
    else
    {
      printResult();
//      found = true;  // Comment this line so the program continues to find the next solution
    }
  }
  else
  {
    for (int i = 1; i < 10; i++)
    {
      grid[row][column] = i;
/*
printResult();
cout << "TTT" << endl;
system("pause");
*/
      if (isValid(row, column))
      {
        // Fill in the next cell
        if (column < 9 - 1)
          search(row, column + 1);
        else if (row < 9 - 1)
          search(row + 1, 0);
        else
        {
          printResult();
//          found = true; // Comment this line so the program continues to find the next solution
        }
      }
    }

    if (!found) grid[row][column] = 0;

  }

  return found;
}

/** Set isFreeCell[i][j] to true if (i, j) is not fixed */
void findFreeCells()
{
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      isFree[i] [j] = true;

  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (grid[i] [j] > 0)
        isFree[i] [j] = false;
}

int main()
{
 // readAPuzzle();
  findFreeCells();

  search(0, 0); // Search for all solutions

  if (c == 0)
    cout << "No solutions" << endl;

  return 0;
}
