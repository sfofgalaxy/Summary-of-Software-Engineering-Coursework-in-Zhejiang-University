#include <iostream>
using namespace std;
#include "employee.h"
#include "manager.h"

void manager::myDuties() const
{	
	cout << "my Duties is " << position << endl;	
} 

void manager::Signing() const // signature
{
	cout << Iam() << endl;
	cout << "I agreed!" << endl;
}


void manager::print() const
{
  	if (name != NULL){
	    cout << "I am a manager." << endl;
		cout << "my name is " << name;
		cout << ", my age is " << age;
		cout << ", my salary is " << salary;
		cout << ", my Duties is  " << position << endl;
	}
	else
		cout << "没有具体信息!\n";
}

float manager::Salary()
{
	salary = float( 4000.50 );
	return salary;
}
