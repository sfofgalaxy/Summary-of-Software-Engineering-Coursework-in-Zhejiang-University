#include <iostream>
#include <string>
using namespace std;
#include "employee.h"
#include "manager.h"

int main()
{ 
   employee ls("����",29,2000);
   ls.SignIn();   //call employee::SignIn();
   ls.print();  //call employee::print()
   ls.Salary(); //call employee::Salary()


   manager zs("����",25,6000,"����");
   zs.myDuties();  //call manager::myDuties()
   zs.Signing();     //call manager::Signing()
   zs.Iam();          //call employee::Iam()�﷨��ȷ��������ȷ
   zs.SignIn();      //call employee::SignIn()�﷨��ȷ��������ȷ
   /*  
   zs.print();     //call employee::print() �﷨��ȷ�����岻��ȷ
   zs.Salary();    //call employee::salary() gotothehouse,but semantic error
   */
   /*
   zs.print();    //call manager::print()
   zs.Salary();   //call manager::Salary()
   */
	//using pointer......
	employee *pe = &ls;
	manager *pm = &zs;
	pe->Salary();
	pm->Salary();

    pe = &zs;//upcasting,why?
    pe->Salary();//but,call employee::Salary().hope: manager::Salary()

   return 0;
	
}

/*�Žӿ�һ���ԣ�����������ʹ����ͬ�Ĳ������֡�
  �Ʊ�������/�����޶�
*/