#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int SIZE = 6;

bool isEvenParity(int matrix[][SIZE]) 
{
  for (int i = 0; i < SIZE; i++) 
  {
    int sum = 0;
    for (int j = 0; j < SIZE; j++)
      sum += matrix[i][j];
    if (sum % 2 != 0)
      return false;
  }
    
  for (int j = 0; j < SIZE; j++)
  {
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
      sum += matrix[i][j];
    if (sum % 2 != 0)
      return false;
  }
        
  return true;  
}

int main()
{
  int matrix[SIZE][SIZE];
  srand(time(0));

  // Initialize matrix and display it
  for (int i = 0; i < SIZE; i++) 
  {
    for (int j = 0; j < SIZE; j++) 
    {
      matrix[i][j] = rand() % 2;
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
    
  if (isEvenParity(matrix))
    cout << "All rows and columns are even" << endl;
  else
    cout << "Not all rows and columns are even" << endl;

  return 0;
}