#include <iostream>
using namespace std;

void reverse(int number) {
  while (number != 0) {
    int remainder = number % 10;
    cout << remainder;
    number = number / 10;
  }
}

int main()
{
  cout << "Enter an integer: ";
  int n;
  cin >> n;

  cout << "The revsesal is ";
  reverse(n);

  return 0;
}
