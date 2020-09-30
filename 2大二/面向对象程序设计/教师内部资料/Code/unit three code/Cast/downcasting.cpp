#include <cassert>
#include <iostream>
using namespace std;

class A 
{
public:
	virtual void print() = 0;
};

class B:public A   
{
public:
	virtual void print()
	{ 
		cout << "I am B." << endl;
	}
	void f()
	{
		cout << "I am a function of B,but isn't a virtual" << endl;
	}
};

class C:public B 
{
public:
	virtual void print()
	{ 
		cout << "I am C." << endl;
	}
	void f()
	{
		cout << "I am a function of C,but isn't a virtual" << endl;
	}
};

class D:public C 
{
public:
	virtual void print()
	{ 
		cout << "I am D." << endl;
	}
	void f()
	{
		cout << "I am a function of D,but isn't a virtual" << endl;
	}
};

void main()
{
	//A a;
	A *p;//基类指针
	p = new D;//upcasting
   	p->print();  //dynamic binding
	//p->f();      //static binding  compile-time error
	
	//(D*)p->f();//强制转换, downcast不总是安全的
	//(C*)p->f();

    /*在C++ 中，為防止downcast 帶來的可能危險，程式中不該做C-style 
	強制轉型,必須改用dynamic_cast 轉型運算子
	*/
	D *pd = dynamic_cast<D*>(p);
    if (pd != NULL)
        pd->f();
}