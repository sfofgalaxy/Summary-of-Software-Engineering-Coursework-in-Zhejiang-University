#include <iostream>
using namespace std;

int main()
{
  // Prompt the user to enter weight in pounds
  cout << "Enter weight in pounds: ";
  double weight;
  cin >> weight;

  // Prompt the user to enter height
  cout << "Enter feet: ";
  double feet;
  cin >> feet;
  cout << "Enter inches: ";
  double inches;
  cin >> inches;

  double height = feet * 12 + inches;

  // Compute BMI
  double bmi = weight * 0.45359237 /
    ((height * 0.0254) * (height * 0.0254));

  // Display result
  cout << "Your BMI is " << bmi << endl;
  if (bmi < 18.5)
    cout << "Underweight" << endl;
  else if (bmi < 25)
    cout << "Normal" << endl;
  else if (bmi < 30)
    cout << "Overweight" << endl;
  else 
    cout << "Obese" << endl;

  return 0;
}