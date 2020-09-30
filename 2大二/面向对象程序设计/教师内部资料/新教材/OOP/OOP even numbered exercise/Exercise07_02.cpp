#include <iostream>
using namespace std;

int main()
{
  const int SIZE = 10;
  int num[SIZE];

  for (int i = 0; i < SIZE; i++) {
    // Read a number
    cout << "Read a number: ";
    cin >> num[i];
  }

  // Display the array
  for (int i = SIZE - 1; i >= 0; i--) {
    cout << num[i] << " ";
  }

  return 0;
}
