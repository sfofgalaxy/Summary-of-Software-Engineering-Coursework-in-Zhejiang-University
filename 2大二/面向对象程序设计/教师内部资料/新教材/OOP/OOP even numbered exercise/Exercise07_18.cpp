/* Find a solution (just one) for the eight queens problem */
#include <iostream>
using namespace std;

int findPosition(int k, int queens[]);
bool isValid(int k, int j, int queens[]);
void printResult(int queens[]);

int main()
{
  // Queen positions
  int queens[8]; // queens are placed at (i, queens[i])

  for (int i = 0; i < 8; i++)
    queens[i] = -1; // -1 indicates that no queen is currently placed in the ith row
  queens[0] = 0; // Initially, place a queen at (0, 0) in the 0th row

  // k - 1 indicates the number of queens placed so far
  // We are looking for a position in the kth row to place a queen
  int k = 1;
  while (k >= 0 && k <= 7)
  {
    // Find a position to place a queen in the kth row
    int j = findPosition(k, queens);
    if (j < 0)
    {
      queens[k] = -1;
      k--; // back track to the previous row
    }
    else
    {
      queens[k] = j;
      k++;
    }
  }

  printResult(queens);

  return 0;
}

int findPosition(int k, int queens[])
{
  int start = queens[k] == -1 ? 0 : queens[k] + 1;

  for (int j = start; j < 8; j++)
  {
    if (isValid(k, j, queens))
      return j; // (k, j) is the place to put the queen now
  }

  return -1;
}

bool isValid(int k, int j, int queens[])
{
  // See if (k, j) is a possible position
  // Check jth column
  for (int i = 0; i < k; i++)
    if (queens[i] == j) return false;

  // Check major diagnol
  for (int row = k - 1, column = j - 1; row >= 0 && column >= 0; row--, column--)
    if (queens[row] == column) return false;

  // Check minor diagnol
  for (int row = k - 1, column = j + 1; row >= 0 && column <= 7; row--, column++)
    if (queens[row] == column) return false;

  return true; // valid
}

/** Print a two-dimensional board to display the queens */
void printResult(int queens[])
{
  for (int i = 0; i < 8; i++)
    cout << i << ", " << queens[i] << endl;
  cout << endl;

  // Display the output
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < queens[i]; j++)
      cout << "| ";
    cout << "|Q|";
    for (int j = queens[i] + 1; j < 8; j++)
      cout << " |";
    cout << endl;
  }
}
