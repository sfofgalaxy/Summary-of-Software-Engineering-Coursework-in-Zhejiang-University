#include "MyObject.h"
#include <iostream.h>

int MyObject::j=0;

MyObject::MyObject(int jj,int ii):k(jj),b()
{
	i=ii;
}

MyObject::MyObject(const MyObject& obj):k(obj.k),b(obj.b),i(obj.i)
{
}

const MyObject MyObject::operator+(const MyObject&) const
{
	MyObject temp(+j,+k);
	return temp;
}

//static int MyObject::get_j()//error
int MyObject::get_j()
{
	return j;  //不能访问某个对象的数据 j + i
}

const MyObject operator+(const MyObject& x,const MyObject& y) //不能加const
{
	return MyObject();
}


void f()
{
   MyObject a, *pa;
   pa = &a; 
   static MyObject b;
   //pa->
   //a.
}


