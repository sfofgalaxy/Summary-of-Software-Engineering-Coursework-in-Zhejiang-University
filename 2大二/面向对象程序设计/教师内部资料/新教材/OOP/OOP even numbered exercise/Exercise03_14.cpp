#include <iostream>
using namespace std;

int main()
{
  // Generate a lottery
  srand(time(0));
  int lottery = rand() % 1000;

  // Prompt the user to enter a guess
  cout << "Enter your lottery pick (three digits): ";
  int guess;
  cin >> guess;

  // Get digits
  int lottery1 = lottery / 100;
  int lottery2 = (lottery % 100) / 10;
  int lottery3 = lottery % 10;

  int guess1 = guess / 100;
  int guess2 = (guess % 100) / 10;
  int guess3 = guess % 10;

  cout << "the lottery number is " << lottery << endl;

  // Check the guess
  if (guess  == lottery)
    cout << "Exact match: you win $10,000";
  else if (guess1 == lottery1 && guess3 == lottery2 && guess2 == lottery3 ||
      guess2 == lottery1 && guess1 == lottery2 && guess3 == lottery3 ||
      guess2 == lottery1 && guess3 == lottery2 && guess1 == lottery3 ||
      guess3 == lottery1 && guess1 == lottery2 && guess2 == lottery3 ||
      guess3 == lottery1 && guess2 == lottery2 && guess1 == lottery3)
    cout << "Match all digits: you win $3,000";
  else if (
      guess3 == lottery1 || guess3 == lottery2 || guess3 == lottery3 ||
      guess2 == lottery1 || guess2 == lottery2 || guess2 == lottery3 ||
      guess1 == lottery1 || guess1 == lottery2 || guess1 == lottery3)
    cout << "Match one digit: you win $1,000";
  else
    cout << "Sorry, no match";

  return 0;
}
