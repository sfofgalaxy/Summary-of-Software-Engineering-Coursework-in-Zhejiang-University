#include <iostream>
#include <string>
using namespace std;
#include "employee.h"
#include "manager.h"

void main()
{ 
	employee ls("李四",29,2000);
    manager zs("张三",29,6000,"科长");
	ls.print();
	ls.Salary();
	zs.print();
	zs.Salary();
    employee *pe;
	manager *pm;
	pe = &ls;
	pm = &zs;
	pe->Salary();
	pm->Salary();

	/*but,在公有继承层次中，基类指针可以指向派生类对象，
	且不需要强制转换，语义也正确(Upcasting) */
	
	pe = &zs;   //upcasting
	pe->Salary();  //still call void employee::print()
   
	void SignIn(employee& e);
    void Signing(manager& m);
    SignIn(ls);
	SignIn(zs);  //Upcasting
    //Signing(ls);  //编译错误
	Signing(zs);
}

void SignIn(employee& e)//签到
{
	e.Iam();
	cout << "I am working!" << endl;
}

void Signing(manager& m)//签字
{
	m.Iam();
	cout << "I agreed" << endl;
}