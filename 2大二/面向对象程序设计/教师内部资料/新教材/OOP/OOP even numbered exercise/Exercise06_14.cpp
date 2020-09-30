#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double computeTax(double income, int r1, int r2, int r3, int r4, int r5)
{
  double tax = 0;

  if (income <= r1)
    tax = income * 0.10;
  else if (income <= r2)
    tax = r1 * 0.10 + (income - r1) * 0.15;
  else if (income <= r3)
    tax = r1 * 0.10 + (r2 - r1) * 0.15 + (income - r2) * 0.27;
  else if (income <= r4)
    tax = r1 * 0.10 + (r2 - r1) * 0.15 + (r3 - r2) * 0.27 + (income - r3) * 0.30;
  else if (income <= r5)
    tax = r1 * 0.10 + (r2 - r1) * 0.15 + (r3 - r2) * 0.27 + (r4 - r3) * 0.30 + (income - r4) * 0.35;
  else
    tax = r1 * 0.10 + (r2 - r1) * 0.15 + (r3 - r2) * 0.27 + (r4 - r3) * 0.30 + (r5 - r4) * 0.35 + (income - r5) * 0.386;

  return tax;
}

double computeTax(int status, double income)
{
  switch (status)
  {
    case 0:
      return computeTax(income, 6000, 27950, 67700, 141250, 307050);
    case 1:
      return computeTax(income, 12000, 46700, 112850, 171950, 307050);
    case 2:
      return computeTax(income, 6000, 23350, 56425, 85975, 153525);
    case 3:
      return computeTax(income, 10000, 37450, 96700, 156600, 307050);
    default:
      return 0;
  }
}

int main()
{
  cout << setw(10) << "taxable" << setw(10) << "Single" << setw(10) << "Married" << setw(10) << "Married"
       << setw(10) << "Head of" << endl;
  cout << setw(10) << "Income" << setw(10) << "Single" << setw(10) << "Joint" << setw(10) << "Separate"
       << setw(10) << "a House" << endl;
  for (int taxableIncome = 50000; taxableIncome <= 60000; taxableIncome += 50)
  {
    cout << setw(10) << taxableIncome << setw(10) << ceil(computeTax(0, taxableIncome)) << setw(10)
         << ceil(computeTax(1, taxableIncome)) << setw(10) << ceil(computeTax(2, taxableIncome)) << setw(10)
         << ceil(computeTax(3, taxableIncome)) << endl;
  }

  return 0;
}
