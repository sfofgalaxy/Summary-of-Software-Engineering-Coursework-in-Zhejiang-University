#include <iostream>
using namespace std;

int main()
{
  cout << "Enter a year: ";
  int year;
  cin >> year;

  cout << "Enter the first day of the year: ";
  int firstDay;
  cin >> firstDay;

  int numberOfDaysInMonth = 0;

  // Display calendar for each month
  for (int month = 1; month <= 12; month++)
  {
    // Display Calendar title
    switch (month)
    {
      case 1:
        cout << "January 1, " << year << " is ";
        numberOfDaysInMonth = 31;
      break;
      case 2:
        cout << "Feburary 1, " << year << " is ";
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
          numberOfDaysInMonth = 29;
        else
          numberOfDaysInMonth = 28;
      break;
      case 3:
        cout << "March 1, " << year << " is ";
        numberOfDaysInMonth = 31;
      break;
      case 4:
        cout << "April 1, " << year << " is ";
        numberOfDaysInMonth = 30;
      break;
      case 5:
        cout << "May 1, " << year << " is ";
        numberOfDaysInMonth = 31;
      break;
      case 6:
        cout << "June 1, " << year << " is ";
        numberOfDaysInMonth = 30;
      break;
      case 7:
        cout << "July 1, " << year << " is ";
        numberOfDaysInMonth = 31;
      break;
      case 8:
        cout << "August 1, " << year << " is ";
        numberOfDaysInMonth = 31;
      break;
      case 9:
        cout << "September 1, " << year << " is ";
        numberOfDaysInMonth = 30;
      break;
      case 10:
        cout << "October 1, " << year << " is ";
        numberOfDaysInMonth = 31;
      break;
      case 11:
        cout << "November 1, " << year << " is ";
        numberOfDaysInMonth = 30;
      break;
      case 12:
        cout << "December 1, " << year << " is ";
        numberOfDaysInMonth = 31;
      break;
    }

    switch (firstDay)
    {
      case 0:
        cout << "Sunday" << endl;
      break;
      case 1:
        cout << "Monday" << endl;
      break;
      case 2:
        cout << "Tuesday" << endl;
      break;
      case 3:
        cout << "Wednesday" << endl;
      break;
      case 4:
        cout << "Thursday" << endl;
      break;
      case 5:
        cout << "Friday" << endl;
      break;
      case 6:
        cout << "Saturday" << endl;
      break;
    }

    // Get the start day for the next month
    firstDay = (firstDay + numberOfDaysInMonth) % 7;
  }

  return 0;
}
