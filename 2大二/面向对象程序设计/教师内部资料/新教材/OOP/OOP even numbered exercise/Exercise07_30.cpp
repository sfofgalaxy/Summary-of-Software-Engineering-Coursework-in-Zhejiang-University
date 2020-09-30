#include <iostream>
#include <string>
using namespace std;

int main()
{
  cout << "Enter a year: ";
  int year;
  cin >> year;
  
  if (year >= 1900) 
    year -= 1900;
  else
    year = 12 - (1900 - year);
    
  string animals[] = {"rat", "ox", "tiger", "rabbit", "dragon", 
      "snake", "horse", "sheep", "monkey", "rooster", "dog", "pig"};

  cout << animals[year % 12] << endl;

  return 0;
}