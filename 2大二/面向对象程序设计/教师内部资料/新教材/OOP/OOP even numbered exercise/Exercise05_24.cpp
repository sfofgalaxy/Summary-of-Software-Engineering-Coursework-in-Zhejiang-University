#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  int numberOfYears;
  double loanAmount;

  // Enter loan amount
  cout << "Enter loan amount, for example 120000.95: ";
  cin >> loanAmount;

  // Enter number of years
  cout << "Enter number of years as an integer, \nfor example 5: ";
  cin >> numberOfYears;

  cout << "Enter yearly interest rate, for example 8.25: ";
  double annualInterestRate;
  cin >> annualInterestRate;

  // Obtain monthly interest rate
  double monthlyInterestRate = annualInterestRate / 1200;

  // Compute mortgage
  double monthlyPayment = loanAmount * monthlyInterestRate / (1 - (pow(1 / (1 + monthlyInterestRate), numberOfYears * 12)));

  double balance = loanAmount;
  double interest;
  double principal;

  cout << "Loan Amount: " << loanAmount << endl;
  cout << "Number of Years: " << numberOfYears << endl;
  cout << "Interest Rate: " << annualInterestRate << "%" << endl;
  cout << endl;
  cout << "Monthly Payment: " << (int)(monthlyPayment * 100) / 100.0 << endl;
  cout << "Total Payment: " << (int)(monthlyPayment * 12 * numberOfYears * 100) / 100.0 << "\n\n";

  // Display the header
  cout << "Payment#\tInterest\tPrincipal\tBalance\n";
  int i;
  for (i = 1; i <= numberOfYears * 12; i++)
  {
    interest = (int)(monthlyInterestRate * balance * 100) / 100.0;
    principal = (int)((monthlyPayment - interest) * 100) / 100.0;
    balance = (int)((balance - principal) * 100) / 100.0;
    cout << i << "\t\t" << interest << "\t\t" << principal << "\t\t" << balance << endl;
  }

  return 0;
}
