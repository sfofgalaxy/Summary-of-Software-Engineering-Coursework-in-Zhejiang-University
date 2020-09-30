#include <iostream>
#include <ctime>
using namespace std;

int main()
{
  // Generate a random number to be guessed
  srand(time(0));

  // Generate the first digit
  int first = rand() % 10;

  // Generate the second digit
  int second;

  while (true)
  {
    second = rand() % 10;

    // Check if two digits are identical
    if (first == second)
      continue;

    break;
  }

  // Prompt the user to enter a guess
  cout << "Enter your lottery pick (two digits): ";
  int guess;
  cin >> guess;

  // Check the guess
  if (guess / 10 == first && guess % 10 == second)
    cout << "Exact match: you win $10,000" << endl;
  else if (guess % 10 == first && guess / 10 == second)
    cout << "Match all digits: you win $3,000" << endl;
  else if (guess % 10 == first || guess % 10 == second
           || guess / 10 == first || guess / 10 == second)
    cout << "Match one digit: you win $1,000" << endl;
  else
    cout << "Sorry, no match";

  return 0;
}
