#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  double monthlyDeposit;
  cout << "Enter the amount to be saved for each month: ";
  cin >> monthlyDeposit;

  double annualInterestRate;
  cout << "Enter the annual interest rate: ";
  cin >> annualInterestRate;
  double monthlyInterestRate = annualInterestRate / 1200;

  double numberOfMonths;
  cout << "Enter the number of months: ";
  cin >> numberOfMonths;

  double currentValue = monthlyDeposit * (1 + monthlyInterestRate);
  for (int i = 1; i < numberOfMonths; i++) {
    currentValue = (currentValue + monthlyDeposit) * (1 + monthlyInterestRate);
  }

  cout << fixed << setprecision(2);
  cout << "After the " << numberOfMonths << "th month, the account value is "
    << currentValue << endl;

  return 0;
}
