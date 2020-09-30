#ifndef MANAGER_H
#define MANAGER_H

class manager : public employee
{
public: 
	manager():employee(), position(NULL)//employee(),可以省略
	{   }

	manager(char * name1,short age1,float salary1,char *position)
		:employee(name1,age1,salary1)
	{
		this->position =  new char[strlen(position)+1];
		strcpy(this->position, position);
	}

	void myDuties() const;
	void Signing() const; // signature
	//redefine
	//void print() const;
	//float Salary();//与父类有相同的接口，但不一样的操作
	
	~manager()
	{
		if (position)	delete[] position;
	}  
private: 
	char *position;
	manager(const manager&);
	manager& operator=(const manager&);
};
#endif
