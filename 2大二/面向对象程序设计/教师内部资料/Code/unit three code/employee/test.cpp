#include <iostream>
#include <string>
using namespace std;
#include "employee.h"
#include "manager.h"

int main()
{ 
   employee ls("李四",29,2000);
   ls.SignIn();   //call employee::SignIn();
   ls.print();  //call employee::print()
   ls.Salary(); //call employee::Salary()


   manager zs("张三",25,6000,"主任");
   zs.myDuties();  //call manager::myDuties()
   zs.Signing();     //call manager::Signing()
   zs.Iam();          //call employee::Iam()语法正确，语义正确
   zs.SignIn();      //call employee::SignIn()语法正确，语义正确
   /*  
   zs.print();     //call employee::print() 语法正确，语义不正确
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

/*⑴接口一致性：基类与子类使用相同的操作名字。
  ⑵本地优先/名字限定
*/