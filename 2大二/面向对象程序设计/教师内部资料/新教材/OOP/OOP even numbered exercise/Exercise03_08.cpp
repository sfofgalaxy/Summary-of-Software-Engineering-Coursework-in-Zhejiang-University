#include <iostream>
using namespace std;

int main()
{
  // Receive the amount
  cout << "Enter an amount in double, for example 11.56: ";
  double amount;
  cin >> amount;

  int remainingAmount = static_cast<int>(amount * 100);

  // Find the number of one dollars
  int numberOfOneDollars = remainingAmount / 100;
  remainingAmount = remainingAmount % 100;

  // Find the number of quarters in the remaining amount
  int numberOfQuarters = remainingAmount / 25;
  remainingAmount = remainingAmount % 25;

  // Find the number of dimes in the remaining amount
  int numberOfDimes = remainingAmount / 10;
  remainingAmount = remainingAmount % 10;

  // Find the number of nickels in the remaining amount
  int numberOfNickels = remainingAmount / 5;
  remainingAmount = remainingAmount % 5;

  // Find the number of pennies in the remaining amount
  int numberOfPennies = remainingAmount;

  // Display results
  cout << "Your amount " << amount << " consists of " << endl;

  if (numberOfOneDollars > 1)
    cout << "    " << numberOfOneDollars << " dollars" << endl;
  else if (numberOfOneDollars == 1)
    cout << "    " << numberOfOneDollars << " dollar" << endl;

  if (numberOfQuarters > 1)
    cout << "    " << numberOfQuarters << " quarters" << endl;
  else if (numberOfQuarters == 1)
    cout << "    " << numberOfQuarters << " quarter" << endl;

  if (numberOfDimes > 1)
    cout << "    " << numberOfQuarters << " dimes" << endl;
  else if (numberOfDimes == 1)
    cout << "    " << numberOfQuarters << " dime" << endl;

  if (numberOfNickels > 1)
    cout << "    " << numberOfNickels << " nickels" << endl;
  else if (numberOfNickels == 1)
    cout << "    " << numberOfNickels << " nickel" << endl;

  if (numberOfPennies > 1)
    cout << "    " << numberOfPennies << " pennies" << endl;
  else if (numberOfPennies == 1)
    cout << "    " << numberOfPennies << " penny" << endl;
}
