#include <iostream>
#include <ctime> // for time function
#include <cmath> // for rand function
using namespace std;

int main()
{
  // 1. Generate three random single-digit integers
  srand(time(0));
  int number1 = rand() % 10;
  int number2 = rand() % 10;
  int number3 = rand() % 10;

  cout << "What is " << number1 << " + " << number2 << " + " << number3 << "? ";
  int answer;
  cin >> answer;

  // 4. Grade the answer and display the result
  if (number1 + number2 + number3 == answer)
    cout << "You are correct!";
  else
    cout << "Your answer is wrong.\n" << number1 << " + " << number2
         << " should be " << (number1 + number2 + number3) << endl;

  return 0;
}
