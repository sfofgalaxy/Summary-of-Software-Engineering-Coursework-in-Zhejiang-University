#include <iostream>
#include <ctime>
using namespace std;

void shuffle(int m[][2], int rowSize)
{
  srand(time(0));

  for (int i = 0; i < rowSize; i++)
  {
    int row = rand() % rowSize;

    // Swap m[row] with m[i]
    for (int j = 0; j < 2; j++)
    {
      int temp = m[i][j];
      m[i][j] = m[row][j];
      m[row][j] = temp;
    }
  }
}

int main()
{
  const int rowSize = 5;
  int m[][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};

  shuffle(m, rowSize);

  for (int i = 0; i < rowSize; i++)
  {
    for (int j = 0; j < 2; j++)
      cout << m[i][j] << " ";
    cout << endl;
  }

  return 0;
}
