#include <iostream>
using namespace std;

int main()
{
  // Obtain the random number 0 or 1
  srand(time(0));
  int number = rand() % 2;

  // Prompt the user to enter a guess
  cout << "Guess head or tail? Enter 0 for head and 1 for tail: ";
  int guess;
  cin >> guess;

  // Check the guess
  if (guess == number)
    cout << "Correct guess" << endl;
  else if (number == 0)
    cout << "Sorry, it is a head" << endl;
  else
    cout << "Sorry, it is a tail" << endl;

  return 0;
}
