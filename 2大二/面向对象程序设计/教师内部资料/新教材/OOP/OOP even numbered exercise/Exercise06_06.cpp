#include <iostream>
using namespace std;

void displayPattern(int n)
{
  for (int row = 1; row <= n; row++)
  {
    // Print spaces
    for (int i = row; i < n; i++)
      cout << "  ";

    // Print numbers
    for (int i = row; i >= 1; i--)
      cout << " " << i;

    cout << endl;
  }
}

int main()
{
  displayPattern(7);

  return 0;
}
