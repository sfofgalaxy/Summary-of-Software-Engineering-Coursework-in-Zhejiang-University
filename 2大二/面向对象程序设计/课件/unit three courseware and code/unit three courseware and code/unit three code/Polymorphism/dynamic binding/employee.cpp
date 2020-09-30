#include <iostream>
using namespace std;
#include "employee.h"

char* employee::Iam() const
{
	return name;
}

void employee::SignIn() const
{
	cout << Iam() << endl;
	cout << "I am working!" << endl;
}

void employee::print() const
{	
	if (name != NULL){
		cout << "I am an employee." << endl;
		cout << "my name is " << name;
		cout << ", my age is " << age;
  		cout << ", my salary is " << salary << endl;
	}
	else
		cout << "没有具体信息！\n";
	
}
float employee::Salary() //计算薪水
{
	salary = 2000.50;
	return salary;
}