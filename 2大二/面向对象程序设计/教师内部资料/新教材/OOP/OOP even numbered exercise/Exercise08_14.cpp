#include <iostream>
using namespace std;

const int N = 4;

int sumRow(int row[]);
int sumColumn(int matrix[][N], int column);

int main()
{
  int matrix[N][N];

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
	    matrix[i][j] = rand() % 2;
      cout << matrix[i][j] << " ";
    }

    cout << endl;
  }

  // Check rows
  int rowSum = sumRow(matrix[0]);
  int rowIndex = 0;
  for (unsigned i = 1; i < N; i++)
  { 
	  if (rowSum < sumRow(matrix[i]))
	  {
      rowSum = sumRow(matrix[i]);
      rowIndex = i;
	  }
  }

  cout << "The largest row index: " << rowIndex << endl;

  // Check columns
  int columnSum = sumColumn(matrix, 0);
  int columnIndex = 0;
  for (unsigned i = 1; i < N; i++)
  { 
    if (columnSum < sumColumn(matrix, i)) 
    {
      columnSum = sumColumn(matrix, i);
      columnIndex = i;
    }
  }

  cout << "The largest column index: " << columnIndex << endl;

  return 0;
}

int sumRow(int row[]) 
{
  int sum = 0;
  for (unsigned i = 0; i < N; i++)
    sum += row[i];
  return sum;
}

int sumColumn(int matrix[][N], int column) 
{
  int sum = 0;
  for (unsigned i = 0; i < N; i++)
    sum += matrix[i][column];
  return sum;
}