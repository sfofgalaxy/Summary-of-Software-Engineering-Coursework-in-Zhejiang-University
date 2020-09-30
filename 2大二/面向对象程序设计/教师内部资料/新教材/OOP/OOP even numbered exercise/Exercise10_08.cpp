#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() 
{
  cout << "Enter the amount: ";
  string amountString;
  cin >> amountString;
    
  int decimalPosition = amountString.find('.');
    
  int amount; // amount in cents
    
  if (decimalPosition == -1)
  {
    amount = atoi(amountString.c_str());
  }
  else 
  {
    string fractionPart = amountString.substr(decimalPosition + 1);
      
    if (fractionPart.length() >= 2) {
      fractionPart = fractionPart.substr(0, 2);
    }
    else if (fractionPart.length() == 1) 
    {
      fractionPart = fractionPart + "0";
    } 
    else 
    {
      fractionPart = fractionPart + "00";
    }
    
    string s = amountString.substr(0, decimalPosition) + fractionPart;
    amount = atoi(s.c_str());
  }

  int remainingAmount = amount;

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
  cout << "Your amount " << amountString << " consists of \n" <<
    "\t" << numberOfOneDollars << " dollars\n" << 
    "\t" << numberOfQuarters << " quarters\n" <<
    "\t" << numberOfDimes << " dimes\n" << 
    "\t" << numberOfNickels << " nickels\n" <<
    "\t" << numberOfPennies << " pennies" << endl;
 
  return 0;
}

