#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
  // Obtain input
  cout << "Enter employee's name: ";
  string name;
  getline(cin, name);
  
  cout << "Enter number of hours worked in a week: ";
  double hours;
  cin >> hours;

  cout << "Enter hourly pay rate: ";
  double payRate;
  cin >> payRate;

  cout << "Enter federal tax withholding rate: ";
  double fedTaxWithholdingRate;
  cin >> fedTaxWithholdingRate;

  cout << "Enter state tax withholding rate: ";
  double stateTaxWithholdingRate;
  cin >> stateTaxWithholdingRate;

  double grossPay = hours * payRate;
  double fedTaxWithholding = grossPay * fedTaxWithholdingRate;
  double stateTaxWithholding = grossPay * stateTaxWithholdingRate;
  double totalDeduction = fedTaxWithholding + stateTaxWithholding;
  double netPay = grossPay - totalDeduction;

  // Obtain output
  cout << "Employee Name: " << name << endl << endl;
  cout << "Hours Worked: " << hours << endl;
  cout << "Pay Rate: $" << payRate << endl;
  cout << "Gross Pay: $" << grossPay << endl;
  cout << "Deductions:" << endl;
  cout << "  Federal Withholding (" << fedTaxWithholdingRate * 100 
    << "%): $" << fixed << setprecision(2) << fedTaxWithholding << endl;
  cout << "  State Withholding (" << stateTaxWithholdingRate * 100 << "%):" 
    << " $" << fixed << setprecision(2) << stateTaxWithholding << endl;
  cout << "  Total Deduction:" << "  $" 
    << (int)(totalDeduction * 100) / 100.0 << endl;
  cout << "Net Pay: $" << (int)(netPay * 100) / 100.0 << endl;

  return 0;
}