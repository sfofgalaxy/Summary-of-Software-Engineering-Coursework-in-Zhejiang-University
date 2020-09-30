#include <iostream>
using namespace std;

int main()
{
  // Receive the amount
  cout << "Enter balance and interest rate (e.g., 3 for 3%): ";
  double balance, annualInterestRate;
  cin >> balance >> annualInterestRate;

  double interest = balance * (annualInterestRate / 1200);

  // Display results
  cout << "The interest rate is " << balance << endl;
  cout << "The balance is " << balance << endl;
  cout << "The interest is " << interest << endl;
}
