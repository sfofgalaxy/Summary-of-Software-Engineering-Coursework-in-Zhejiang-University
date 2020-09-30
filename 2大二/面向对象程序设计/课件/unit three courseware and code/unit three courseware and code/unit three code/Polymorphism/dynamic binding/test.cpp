#include <iostream>
#include <string>
using namespace std;
#include "employee.h"
#include "manager.h"

int main()
{ 
   employee ls("����",29,2000);
   manager zs("����",25,6000,"�Ƴ�");
   employee *pe;
   manager *pm;

   ls.Salary();   //static binding
   zs.Salary(); //static binding
  
   pe = &zs;     //upcasting
   pe->Salary(); // dynamic binding
   //pe->SignIn(); static binding,call employee::SignIn()
   //pe->Signing(); //error

   employee &rhs = zs; //upcasting
   rhs.Salary();    //dynamic binding
   rhs.SignIn(); //static binding,call employee::SignIn()
   //rhs.Signing(); //error
   /*
   employee *p1;
   p1 = new manager("����",32,9000,"������");
   p1->Salary();
   delete p1;
   */
   return 0;
	
}