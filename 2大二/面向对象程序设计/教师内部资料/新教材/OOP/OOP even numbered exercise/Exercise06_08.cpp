#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/** Converts from feet to meters */
double footToMeter(double foot)
{
  return 0.305 * foot;
}

/** Converts from meters to feet */
double meterToFoot(double meter)
{
  return (1 / 0.305) * meter;
}

int main()
{
  cout << setw(12) << "Feet" << setw(12) << "Meters" << setw(12) << "|" << setw(12) << "Meters"
    << setw(12) << "Feet" << endl;
  cout << "-----------------------------------------------------------------------------" << endl;

  double foot = 1; double meter = 20;
  for (int i = 1; i <= 10; foot++, meter += 5, i++)
  {
    cout << setw(12) << foot << setw(12) << footToMeter(foot) << setw(12) <<
   "|" << setw(12) << meter << setw(12) << meterToFoot(meter) << endl;
  }

  return 0;
}
