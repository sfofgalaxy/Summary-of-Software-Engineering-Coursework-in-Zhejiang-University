#include <stdlib.h>
int x;    //��������,in the global score
void f(); //����������in the global score 

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
/*�����ڵ�ǰ���뵥Ԫ�У����������ռ�֮�⣩��
ֱ��ʹ�����������ռ��еĳ�Ա���ƣ�
�����ڵ�ǰ���뵥Ԫ֮�⣬���ǲ��ɼ��ġ�
*/
namespace  // unnamed namespace
{
	void f(){}
	void g(){}
}

/*
in global score�У�ʹ���ڲ����ֿռ��еı����ͺ���
*/
void f()    //��������
{
	A::f(); 
	g();
}
int main()
{
	::f();
	//f();//complie-time error��
	g();
	A::A_1::f();
	return EXIT_SUCCESS;
}

