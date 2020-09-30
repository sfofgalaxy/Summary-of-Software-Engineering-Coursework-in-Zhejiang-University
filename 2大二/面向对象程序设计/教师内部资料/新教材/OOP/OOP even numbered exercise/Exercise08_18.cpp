#include <iostream>
using namespace std;

const int N = 3;

void displayMatrix(double A[][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cout << A[i][j] << " ";
    cout << endl;
  }
}

double deltaA(double A[][N])
{
  double result = A[0][0] * A[1][1] * A[2][2] +
    A[2][0] * A[0][1] * A[1][2] + A[0][2] * A[1][0] * A[2][1] -
    A[0][2] * A[1][1] * A[2][0] - A[0][0] * A[1][2] * A[2][1] -
    A[2][2] * A[1][0] * A[0][1];
  return result;
}

void inverse(double A[][N], double inverseOfA[][N])
{
  double determinant = deltaA(A);
  inverseOfA[0][0] = (A[1][1] * A[2][2] - A[1][2] * A[2][1]) / determinant;
  inverseOfA[0][1] = (A[0][2] * A[2][1] - A[0][1] * A[2][2]) / determinant;
  inverseOfA[0][2] = (A[0][1] * A[1][2] - A[0][2] * A[1][1]) / determinant;
  inverseOfA[1][0] = (A[1][2] * A[2][0] - A[1][0] * A[2][2]) / determinant;
  inverseOfA[1][1] = (A[0][0] * A[2][2] - A[0][2] * A[2][0]) / determinant;
  inverseOfA[1][2] = (A[0][2] * A[1][0] - A[0][0] * A[1][2]) / determinant;
  inverseOfA[2][0] = (A[1][0] * A[2][1] - A[1][1] * A[2][0]) / determinant;
  inverseOfA[2][1] = (A[0][1] * A[2][0] - A[0][0] * A[2][1]) / determinant;
  inverseOfA[2][2] = (A[0][0] * A[1][1] - A[0][1] * A[1][0]) / determinant;
}

int main()
{
  double A[N][N];
  cout << "Enter a11, a12, a13, a21, a22, a23, a31, a32, a33: ";
  cin >> A[0][0] >> A[0][1] >> A[0][2] >>
    A[1][0] >> A[1][1] >> A[1][2] >>
    A[2][0] >> A[2][1] >> A[2][2];

  if (deltaA(A) == 0)
    cout << "No inverse matrix" << endl;
  else
  {
    double inverseA[N][N];
    inverse(A, inverseA);
    displayMatrix(inverseA);
  }

  return 0;
}
