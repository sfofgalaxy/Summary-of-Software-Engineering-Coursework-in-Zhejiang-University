#include <iostream>
#include <string>
using namespace std;

class Person{
private:
	char* name;
	short age;
	char gender;/*the character ��M�� for male and ��F�� for female. */
public:
	Person(const char* name,short age,char gender)//ע1
	{ 
		this->name = new char[strlen(name) + 1];
		strcpy(this->name,name);
		this->age = age;
		this->gender = gender;	  
		cout << " I am in person(......)" << endl;
	}
		
	~Person()		//�����˻������������
	{   
		delete[] name;	 //ע2
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
	virtual ~Student()//�����������������������
	{  
		delete[] major; 
		cout << " I am in ~Student()......" << endl;
	}
};

/*
int main()
{
	Student m("����",26,'F',"C����");
	
      �ȵ��û��๹�캯�����ٵ��������๹�캯��
      �ȵ��������������������ٵ��û�����������
      Person(...)
      Student(...)
      ~Student()
      ~Person()
    
  return 0;
}*///û�����⣡

int main()
{
	Person* pointer = new Student("����",26,'F', "C����");//����ָ��ָ�����������
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

