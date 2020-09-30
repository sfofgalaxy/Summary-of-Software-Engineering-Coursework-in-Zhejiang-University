#include <iostream>
using namespace std;

class parent{
public:
	void f(int a)
	{
		cout << " call void parent::f(int a)." << endl;
	}
	int f(int a , double d)
	{
		cout << " call int parent::f(int a,double d)." << endl;
		return 0;
	}
	void f(char c)
	{
		cout << " call void child::f(char c)" << endl;
	}
};

class child : public parent{
public:
	
   //1:redefine, Name Hiding
	
	void f(int a)  
	{
		cout << " call void child::f(int a)" << endl;
	}
	/*
	2:overriding, Name Hiding
	void f(double a)  
	{
		cout << " call void child::f(int a)" << endl;
	}*/
    //or

/*
	int f(int a)
	{
		cout << " call int child::f(int a)" << endl;
		return 0;
	}
*/
//	void f()
//	{}

};

void main()
{
	parent p;
	p.f(1);     //call void parent::f(int)
	p.f(1,1.1);
	p.f('c');

	child c;
	c.f(1);    //call child::f(int)
	c.f('c');  
     //c.f(1, 1.1);  //compile-time error
	c.parent::f(1, 1.1);

}