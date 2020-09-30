#include <iostream>
#include <string>
using namespace std;

class Person{
private:
	char* name;
	short age;
	char gender;/*the character ‘M’ for male and ‘F’ for female. */
public:
	Person(const char* name,short age,char gender)//注1
	{ 
		this->name = new char[strlen(name) + 1];
		strcpy(this->name,name);
		this->age = age;
		this->gender = gender;	  
		cout << " I am in person(......)" << endl;
	}
		
	~Person()		//定义了基类的析构函数
	{   
		delete[] name;	 //注2
		cout << " I am in ~person()......" << endl;
	}
};

class Student:public Person{
private:
	char *major;
public:
	Student(char*name,short age,char gender,char *major):Person(name,age,gender)
	{  
		this->major = new char[strlen(major) + 1];
		strcpy(this->major,major);	
		cout << " I am in student(.....)" << endl;
	}
	virtual ~Student()//定义了派生类的析构函数。
	{  
		delete[] major; 
		cout << " I am in ~Student()......" << endl;
	}
};

/*
int main()
{
	Student m("张三",26,'F',"C语言");
	
      先调用基类构造函数、再调用派生类构造函数
      先调用派生类析构函数、再调用基类析构函数
      Person(...)
      Student(...)
      ~Student()
      ~Person()
    
  return 0;
}*///没有问题！

int main()
{
	Person* pointer = new Student("张三",26,'F', "C语言");//基类指针指向派生类对象
	//using this Object
	delete pointer;	 
	return 0;
}
/*
Person(...)
Student(...)
~Person()

hoping:
Person(..)
Student(..)
~Student()
~Person()
*/

