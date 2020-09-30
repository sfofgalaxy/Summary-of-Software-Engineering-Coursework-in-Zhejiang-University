#include <iostream>
using namespace std;

int main()
{
  const int N = 10;
  int numbers[N];

  cout << "Enter ten integers: ";
  for (int i = 0; i < N; i++)
    cin >> numbers[i];

  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++)
      cout << numbers[i] << " " << numbers[j] << endl;

  return 0;
}
