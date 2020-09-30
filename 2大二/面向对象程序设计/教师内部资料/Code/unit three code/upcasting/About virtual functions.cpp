
//虚函数的使用
#include <iostream>
using namespace std;

class parent{
public: 
		virtual void f(int a=10)
		{	
			cout<<"Here is parent "<<a<<endl;
		}
		void g()
		{	cout << "Here is void parent::g()" << endl;
		}
};
class child:public parent{
public:
	virtual void f(int a=20);
};

void child::f(int a)
{	
	cout<<"Here is child "<<a<<endl;
}

 void g( parent* p)
 {
	 p->f(3);
 }

int main()
{	
	parent father,*pointer;
	child son;

	pointer = &father;
	pointer -> f();//dynamic binding，调用parent::f(int)
	pointer = &son; //upcasting
	pointer -> f();//dynamic binding，调用child::f(int)
	/*但是，由于pointer的静态类型是parent*，这个函数调用的缺省参数值是从parent类中取得的，而不是child类！*/

	parent& p = father;//dynamic binding，调用parent::f(int)
	p.f(2);
	parent& q = son;//基类引用引用派生类对象
	q.f(3);	      //dynamic binding 调用child::f(int)
   
	son.f(2);//static binding	or early binding 调用child::f(int)
	return 0;
}


/*
#include <iostream>
using namespace std;
class parent{
public: 
	virtual void f(int a)
	{	
		cout<<"Here is parent "<<a<<endl;
	}
};
class child:public parent{
public:
	
	virtual int  f(float a)  //与基类同名函数参数方面不一致
	{	
		cout<<"Here is child "<<a<<endl;
		return 0;
	}
//	virtual int f(int a)//×基类与派生类的同名函数，只是返回类型不一样，编译器认为它有二义性。
//   {return 0;}
};

virtual不起作用，child::f(float)和parent::f(int)是重载函数，使用基类指针不能进行动态束定
使用时注意：Name Hiding


int main()
{
	parent father,*pointer;
	child son;
	pointer = &father;
	pointer ->f(0); //静态binding  调用parent::f(int)

	pointer = &son; //upcasting
	pointer ->f(1.0); //使用类型转换int(1.0),再调用parent::f(int)
    

	child *pointer1 = &son;
	pointer1->f(1.0); // 调用child::f(1.0)
	pointer1->f(1);// 调用child::f( float(1) )  name hiding名字隐藏
	pointer1->parent::f(1);
	
	son.f(1.0);  //调用child::f(1.0)
	son.f(1);  //调用child::f( float(1) )  名字隐藏
	
	return 0;
}
*/
/*
#include <iostream>
using namespace std;
class parent{
public: 
	virtual void f(int a)
	{	
		cout<<"Here is parent "<<a<<endl;
	}
};
class child:public parent{
public:
	virtual int f(int a)//×基类与派生类的同名函数，只是返回类型不一样，编译器认为它有二义性。
   {
	   return 0;
	}
};

int main()
{
	return 0;
}
*/