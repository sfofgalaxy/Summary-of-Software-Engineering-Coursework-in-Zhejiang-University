#include <iostream>
using namespace std;

int main()
{
  cout << "Enter the amount of water in kilograms: ";
  double mass;
  cin >> mass;

  cout << "Enter the initial temperature: ";
  double initialTemperature;
  cin >> initialTemperature;

  cout << "Enter the final temperature: ";
  double finalTemperature;
  cin >> finalTemperature;

  double energy =
    mass * (finalTemperature - initialTemperature) * 4184;

  cout << "The energy needed is " << energy;

  return 0;
}
