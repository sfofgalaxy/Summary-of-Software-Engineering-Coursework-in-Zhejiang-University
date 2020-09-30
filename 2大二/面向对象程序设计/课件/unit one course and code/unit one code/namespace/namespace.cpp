#include <stdlib.h>
int x;    //变量定义,in the global score
void f(); //函数声明，in the global score 

namespace A {
	float x;
	void f()
	{
		x = 0;   //A::x
		::x = x + 1;   //::x in the global score
        //x = A_1::x;
		//B::f();
	}
	namespace A_1{
		int x;
		void f()
		{
			A::x = 1.1;  
		}
	}
	void g()
	{
		x = A_1::x;
	}	
}
namespace B
{
	int x;  //B::x
	void f()
	{
		A::f();
	}
}
/*可以在当前编译单元中（无名命名空间之外），
直接使用无名命名空间中的成员名称，
但是在当前编译单元之外，它是不可见的。
*/
namespace  // unnamed namespace
{
	void f(){}
	void g(){}
}

/*
in global score中，使用内层名字空间中的变量和函数
*/
void f()    //函数定义
{
	A::f(); 
	g();
}
int main()
{
	::f();
	//f();//complie-time error，
	g();
	A::A_1::f();
	return EXIT_SUCCESS;
}

