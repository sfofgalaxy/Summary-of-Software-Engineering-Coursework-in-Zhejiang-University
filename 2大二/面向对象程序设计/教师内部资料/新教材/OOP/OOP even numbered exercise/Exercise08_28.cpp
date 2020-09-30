#include <iostream>
using namespace std;

const int SIZE = 3;

bool equals(const int m1[][SIZE], const int m2[][SIZE]);

int main()
{
  cout << "Enter m1 (a 3 by 3 matrix) row by row: ";
  int m1[SIZE][SIZE];
    
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      cin >> m1[i][j];

  cout << "Enter m2 (a 3 by 3 matrix) row by row: ";
  int m2[SIZE][SIZE];
    
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      cin >> m2[i][j];

  if (equals(m1, m2))
    cout << "The two arrays are strictly equal" << endl;
  else
    cout << "The two arrays are not strictly equal" << endl;

  return 0;
}

bool equals(const int m1[][SIZE], const int m2[][SIZE])
{
  for (int i = 0; i < SIZE; i++)
  	for (int j = 0; j < SIZE; j++)
      if (m1[i][j] != m2[i][j])
  		return false;
  		
  return true;
}