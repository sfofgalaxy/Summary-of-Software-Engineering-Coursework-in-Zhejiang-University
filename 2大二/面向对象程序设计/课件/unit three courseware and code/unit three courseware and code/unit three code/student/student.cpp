#include "student.h"
#include <string>
#include <malloc.h>
#include <iostream>
using namespace std;

Student::Student(const char* name,short age,char gender[])
{ 
	//this->name = name; //使用Student有问题
	this->name = (char*)malloc(strlen(name)+1);
	strcpy(this->name,name);
	this->age = age;
	strcpy(this->gender,gender);	  
}

Student::Student()
{
	name = NULL;
	age = 0;
	gender[0] = '\0';
}

/*
void Student::destroy()
{
	free(name);
}
*/
Student::~Student()	
{   
	if (name != NULL) free(name);
}

void Student::print()
{
	cout << "my name is " << name << endl;
	cout << "my age is " << age << endl;
	cout << "I is " << gender << "生!" << endl;
}

char* Student::get_name() const
{
	return name;
}