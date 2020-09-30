#include <iostream>
using namespace std;

const int SIZE = 2;

bool linearEquation(const double a[][SIZE], const double b[], 
  double result[]);

int main()
{
  cout << "Enter a00, a01, a10, a11, b0, b1: ";
  double a[SIZE][SIZE];
    
  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++)
      cin >> a[i][j];

  double b[SIZE];    
  for (int i = 0; i < SIZE; i++)
    cin >> b[i];

  double result[SIZE];
  bool status = linearEquation(a, b, result);
	    
  if (status) 
    cout << "x is " << result[0] << " and y is " <<  result[1] << endl;
  else 
    cout << "The equation has no solution" << endl;

  return 0;
}

bool linearEquation(const double a[][SIZE], const double b[], 
  double result[])
{
  double detA = a[0][0] * a[1][1] - a[0][1] * a[1][0];
  if (detA == 0) 
    return false;
  else 
  {
    result[0] = (b[0] * a[1][1] - b[1] * a[0][1]) / detA;
    result[1] = (b[1] * a[0][0] - b[0] * a[1][0]) / detA;
      
    return true;
  }
}