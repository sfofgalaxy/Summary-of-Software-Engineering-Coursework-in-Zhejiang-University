#include <iostream>
#include <vector>
using namespace std;

const int N = 4;

int sumRow(vector<int> row);
int sumColumn(vector< vector<int> > matrix, int column);

int main()
{
  vector< vector<int> > matrix;

  for (int i = 0; i < N; i++)
  {
    matrix.push_back(vector<int>());
    for (int j = 0; j < N; j++)
    {
	    matrix[i].push_back(rand() % 2);
        cout << matrix[i][j] << " ";
    }

    cout << endl;
  }

  // Check rows
  int rowSum = sumRow(matrix[0]);
  vector<int> rowList(1);
  for (unsigned i = 1; i < N; i++)
  { 
	if (rowSum < sumRow(matrix[i]))
	{
    rowSum = sumRow(matrix[i]);
    rowList.clear();
	  rowList.push_back(i);
	}
	else if (rowSum == sumRow(matrix[i]))
    rowList.push_back(i);
  }

  cout << "The largest row index: ";
  for (unsigned i = 0; i < rowList.size() - 1; i++)
    cout << rowList[i] << ", ";
  cout << rowList[rowList.size() - 1] << endl;

  // Check columns
  int columnSum = sumColumn(matrix, 0);
  vector<int> columnList(1);
  for (unsigned i = 1; i < N; i++)
  { 
	if (rowSum < sumColumn(matrix, i))
	{
      columnSum = sumColumn(matrix, i);
      columnList.clear();
	  columnList.push_back(i);
	}
	else if (columnSum == sumColumn(matrix, i))
      columnList.push_back(i);
  }

  cout << "The largest column index: ";
  for (unsigned i = 0; i < columnList.size() - 1; i++)
    cout << columnList[i] << ", ";
  cout << columnList[columnList.size() - 1] << endl;

  return 0;
}

int sumRow(vector<int> row) 
{
  int sum = 0;
  for (unsigned i = 0; i < row.size(); i++)
    sum += row[i];
  return sum;
}

int sumColumn(vector< vector<int> > matrix, int column) 
{
  int sum = 0;
  for (unsigned i = 0; i < matrix.size(); i++)
    sum += matrix[i][column];
  return sum;
}