#include <iostream>
using namespace std;

int main()
{
  // Prompt the user to enter weight in pounds
  cout << "Enter weight in pounds: ";
  double weight;
  cin >> weight;

  // Prompt the user to enter height in inches
  cout << "Enter height in inches: ";
  double height;
  cin >> height;

  double bmi = weight * 0.45359237 / (height * 0.0254 * height * 0.0254);

  cout << "BMI is " << bmi << endl;

  return 0;
}
