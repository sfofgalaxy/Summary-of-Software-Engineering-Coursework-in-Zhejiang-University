#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

void printMatrix(int n) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        cout << rand() % 2 << " ";

      cout << endl;
    }
}

int main()
{
  srand(time(0));
  printMatrix(3);
  return 0;
}
