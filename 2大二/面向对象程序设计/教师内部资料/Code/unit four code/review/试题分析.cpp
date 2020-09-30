/*
//函数模板
#include <iostream>
using namespace std;

void f(int i)     
{ 
	cout << "f(int)=" << i << endl; 
}
void f(float i)  
{ 
	cout << "f(float)=" << i << endl; 
}
void f(char i)  
{ 
	cout << "f(char)=" << i << endl; 
}
void f(double i) 
{ 
	cout << "f(double)=" << i << endl; 
}
template <class T>
void f(T i)  
{ 
	cout << "f(T)=" << i << endl; 
}
void main() 
{
	f(1);
    f("a");
	f(1/11);
    f(1.0);
}
*/

//correct
#include <iostream>
using namespace std;

class two;
class one{ 
private: 
	int a; 
public: 
	void func(two&); 
}; 
class two{ 
private: 
	int b; 
	friend void one::func(two&); 
}; 

void one::func(two& r) 
{ 
	a=r.b; 
}

void main()
{
}

/*
#include <iostream>
using namespace std;

class A
{
public:
	virtual void f() const
	{
		cout << "A::f()" << endl;
	}
	void g() const
	{
		cout << "A::g()" << endl;
	}
};

class AA : public A
{
public:
	virtual void f() //去掉const调试
	{
		cout << "AA::f()" << endl;
	}
	void g() const
	{
		cout << "AA::g()" << endl;
	}
};

A *f(AA *aa) 
{	
	return aa;	//upcasting
}

int main()
{
	const AA bb;
	const A* q = &bb;
	q->f();
	bb.f();

	AA aa;
	A *p = &aa;
	f(&aa)->f(); f(&aa)->g();  
	dynamic_cast<AA*>(p)->f();
	dynamic_cast<AA*>(p)->g();

	return 0;
}
*/



/*
class A{};

class B
{
public:
	void createA(A* p) const; // 改为A**，or A* &
};

void B::createA(A* p) const//并加上const	
{
	p = new A;	//改为*p = new A;or p = new A;
	//p为局部指针变量
}

void main()
{ 
	A *pa;
	B b;
	b.createA(pa);
}
*/

