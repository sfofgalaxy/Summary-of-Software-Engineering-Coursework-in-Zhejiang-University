#include "student.h"
#include <string>
#include <malloc.h>
#include <iostream>

double Student::classFee  = 0.0;

Student::Student(const char* name,short age,char gender[])
{ 
	this->name = (char*)malloc(strlen(name)+1);
	strcpy(this->name,name);
	this->age = age;
	strcpy(this->gender,gender);	 
	//classFee = 0.0; //Non-compliant
}

Student::Student()
{
	name = NULL;
	age = 0;
	gender[0] = '\0';
}

Student::~Student()	
{   
//	free(name);	
	if (name != NULL)
	   free(name);
}

void Student::print() const
{
	using std::cout;
	using std::endl;
	cout << "my name is " << this->name << endl;
	cout << "my age is " << this->age << endl;
	cout << "I is " << gender << endl;
    cout << "now our classFee is: " << classFee << endl;
}

char* Student::get_name() const
{
	return name;
}

void Student::setClassFee(double money) //½»°à·Ñ
{
    classFee += money;
}