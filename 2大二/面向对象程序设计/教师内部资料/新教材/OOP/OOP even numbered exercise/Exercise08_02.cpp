#include <iostream>
using namespace std;

const int SIZE = 4;

double sumMajorDiagonal(const double m[][SIZE])
{
  double sum = 0;

  for (int i = 0; i < SIZE; i++)
      sum += m[i][i];

  return sum;
}

int main()
{
  double matrix[SIZE][SIZE];

  cout << "Enter a 4 by 4 matrix row by row: " << endl;

  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      cin >> matrix[i][j];

  cout << "Sum of the elements in the major diagonal is "
    << sumMajorDiagonal(matrix) << endl;

  return 0;
}
