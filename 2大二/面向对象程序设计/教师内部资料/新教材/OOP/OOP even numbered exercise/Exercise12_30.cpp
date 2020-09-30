#include <iostream>
#include <vector>
using namespace std;

int main()
{    
  cout << "Enter the length of a square matrix: ";
  int n;
  cin >> n;
    
  vector< vector<int>> matrix;
  bool isSameOnARow = false, isSameOnAColumn = false,
      isSameOnADiagonal = false, isSameOnASubdiagonal = false;

  for (int i = 0; i < n; i++) 
  {
	matrix.push_back(vector<int>());
    for (int j = 0; j < n; j++) 
	{
      matrix[i].push_back(rand() % 2);
      cout << matrix[i][j] << " ";
    }

	cout << endl;
  }

  // Check rows
  for (int i = 0; i < n; i++) 
  {
    bool same = true;
    for (int j = 1; j < n; j++) 
	{
      if (matrix[i][0] != matrix[i][j]) 
	  {
        same = false;
        break;
      }
    }
    if (same) 
	{
      cout << "All " << matrix[i][0] << "'s on row " << i << endl;
      isSameOnARow = true;
    }
  }

  // Check columns
  for (int j = 0; j < n; j++) 
  {
    bool same = true;
    for (int i = 1; i < n; i++) 
	{
      if (matrix[0][j] != matrix[i][j]) 
	  {
        same = false;
        break;
      }
    }

    if (same) 
	{
      cout << "All " << matrix[0][j] << "'s on column " << j << endl;
      isSameOnAColumn = true;
    }
  }

  // Check major diagonal
  bool same = true;
  for (int i = 1; i < n; i++) 
  {
    if (matrix[0][0] != matrix[i][i])
	{
      same = false;
      break;
    }
  }

  if (same) 
  {
    cout << "All " + matrix[0][0] << "'s on major diagonal" << endl;
    isSameOnADiagonal = true;
  }

  // Check subdiagonal
  same = true;
  for (int i = 1; i < n; i++) 
  {
    if (matrix[0][n - 1] != matrix[i][n - 1 - i]) 
	{
      same = false;
      break;
    }
  }
  if (same)
  {
    cout << "All " << matrix[0][n - 1] << "'s on sub-diagonal" << endl;
    isSameOnASubdiagonal = true;
  }
    
  if (!isSameOnARow) 
    cout << "No same numbers on a row" << endl;

  if (!isSameOnAColumn) 
    cout << "No same numbers on a column" << endl;

    if (!isSameOnADiagonal) 
      cout << "No same numbers on the major diagonal" << endl;

    if (!isSameOnASubdiagonal) 
      cout << "No same numbers on the sub-diagonal" << endl;

  return 0;
}