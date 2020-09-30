#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  double commission = 0;
  double salesAmount = 1;

  // Enter the desired commission
  cout << "Enter the desired commission: ";

  double commissionSought;
  cin >> commissionSought;


  for (salesAmount = 1; commission < commissionSought; salesAmount++)
  {
    // Compute commission
    if (salesAmount >= 10001)
      commission = 5000 * 0.08 + 5000 * 0.1 + (salesAmount - 10000) * 0.12;
    else if (salesAmount >= 5001)
      commission = 5000 * 0.08 + (salesAmount - 5000) * 0.10;
    else
      commission = salesAmount * 0.08;
  }

  // Display the sales amount
  cout << "The sales amount " << salesAmount << " is needed to make a commission of $" << commissionSought;

  return 0;
}
