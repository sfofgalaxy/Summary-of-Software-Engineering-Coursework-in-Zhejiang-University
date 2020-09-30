#include <iostream>
#include <string>
using namespace std;

int main()
{
  cout << "Enter a year: ";
  int year;
  cin >> year;

  cout << "Enter a month (first three letters with the first letter in uppercase): ";
  string month;
  cin >> month;

  if (month == "Jan" || month == "Mar" || month == "May" 
      || month == "Jul" || month == "Aug" || month == "Oct" || month == "Dec")
    cout << month << " " << year << " has 31 days" << endl;
  else if (month == "Apr" || month == "Jun" || month == "Sep" || month == "Nov")
    cout << month << " " << year << " has 30 days" << endl;
  else if (month == "Feb")
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
      cout << month << " " << year << " has 29 days" << endl;
    else
      cout << month << " " << year << " has 28 days" << endl;
  else
    cout << month << " is not a correct month name " << endl;

  return 0;
}