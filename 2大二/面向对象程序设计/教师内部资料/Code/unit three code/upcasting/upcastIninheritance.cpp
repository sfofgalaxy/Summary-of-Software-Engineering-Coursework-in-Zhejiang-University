#include <iostream>
#include <string>
using namespace std;
#include "employee.h"
#include "manager.h"

void main()
{ 
	employee ls("����",29,2000);
    manager zs("����",29,6000,"�Ƴ�");
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

	/*but,�ڹ��м̳в���У�����ָ�����ָ�����������
	�Ҳ���Ҫǿ��ת��������Ҳ��ȷ(Upcasting) */
	
	pe = &zs;   //upcasting
	pe->Salary();  //still call void employee::print()
   
	void SignIn(employee& e);
    void Signing(manager& m);
    SignIn(ls);
	SignIn(zs);  //Upcasting
    //Signing(ls);  //�������
	Signing(zs);
}

void SignIn(employee& e)//ǩ��
{
	e.Iam();
	cout << "I am working!" << endl;
}

void Signing(manager& m)//ǩ��
{
	m.Iam();
	cout << "I agreed" << endl;
}