#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class employee{
public: 
	employee(): name(0),age(0),salary(0)
	{}
	employee(char * name,short age,float salary)
	{
		//this->name = name; 
		this->name = new char[::strlen(name)+1];
		::strcpy(this->name,name);
		this->age = age;
		this->salary = salary;	
	}
	
	char* Iam() const;
	void SignIn() const;  //sign in
	virtual void print() const;
	virtual float Salary();

	~employee()
	{	
		if(name!=NULL)
		   delete[] name;	
	}
protected:
	char *name;
	short age;
	float salary;
private:
	employee(const employee&);
	employee& operator=(const employee&);
};
#endif

/*
employee(char * name1=0,short age1=0,float salary1=0.0)
{		
	if(name1){
	   name = new char[::strlen(name1)+1];
	   ::strcpy(name,name1);
	}
	age = age1;
	salary = salary1;	
}
employee m;
employee m("캐캐");
employee m("캐캐",20);
employee m("캐캐",20,4000);

宅
employee():name(0),age(0),salary(0)
{}
employee(char * name1,short age1,float salary1)
{...}
employee m;
employee m("캐캐",20,4000);
*/