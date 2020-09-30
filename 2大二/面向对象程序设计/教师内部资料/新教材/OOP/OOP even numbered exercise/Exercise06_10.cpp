#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double computeCommission(double salesAmount) {
  double commission;

  if (salesAmount >= 10000.01)
    commission =
    5000 * 0.08 + 5000 * 0.1 + (salesAmount - 10000) * 0.12;
  else if (salesAmount >= 5000.01)
    commission = 5000 * 0.08 + (salesAmount - 5000) * 0.10;
  else
    commission = salesAmount * 0.08;

  return commission;
}

int main()
{
  cout << setw(12) << "salesAmount" << setw(12) << "Commission" << endl;

  for (int salesAmount = 10000; salesAmount <= 100000; salesAmount = salesAmount + 5000) {
    cout << setw(12) << salesAmount << setw(12) << computeCommission(salesAmount) << endl;
  }

  return 0;
}
