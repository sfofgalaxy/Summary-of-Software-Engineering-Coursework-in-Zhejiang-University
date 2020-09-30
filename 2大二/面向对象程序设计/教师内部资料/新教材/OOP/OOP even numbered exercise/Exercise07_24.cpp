#include <iostream>
using namespace std;

bool isConsecutiveFour(const int values[], int size);
  
int main()
{
  const int MAX_SIZE = 80;
  cout << "Enter the number of values: ";
  int size;
  cin >> size;
  
  int values[MAX_SIZE];
    
  cout << "Enter the values: ";
  for (int i = 0; i < size; i++)
    cin >> values[i];
    
  if (isConsecutiveFour(values, size))
	cout << "The series has consecutive fours" << endl;
  else
    cout << "The series has no consecutive fours" << endl;

  return 0;
}


bool isConsecutiveFour(const int values[], int size)
{    
  for (int i = 0; i < size - 3; i++) 
  {
	bool isEqual = true;        
	for (int j = i; j < i + 3; j++) 
	{
	  if (values[j] != values[j + 1]) 
	  {
		isEqual = false;
		break;
	  }
	}
	 
	if (isEqual) return true;
  }

  return false;
}
