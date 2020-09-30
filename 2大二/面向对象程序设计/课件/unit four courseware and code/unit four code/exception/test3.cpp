#include <iostream>
#include <string>
using namespace std;
class A{
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
};
class MyException{
public:
	MyException(string name="none"):m_name(name)
	{
		cout << "构造一个MyException异常对象，名称为:"<<m_name<< endl;
	}

	MyException(const MyException& old_e)
	{
		m_name = old_e.m_name;
		cout << "拷贝一个MyException异常对象，名称为:"<<m_name<< endl;
	}
	MyException& operator= (const MyException& old_e)
	{
		m_name = old_e.m_name;
		cout << "赋值拷贝一个MyException异常对象，名称为:"<<m_name<< endl;
		return *this;
	}

	virtual ~ MyException () 
	{
		cout << "销毁一个MyException异常对象，名称为:" <<m_name<< endl;
	}
	
	string GetName() {return m_name;}

protected:
	string m_name;
};

void main()
{ 
	try
	{
		A a;
		{
			// 构造一个异常对象，这是局部变量
			MyException ex_obj1("ex_obj1");

			// 这里抛出异常对象
			// 注意这时VC编译器会复制一份新的异常对象，临时变量
			throw ex_obj1;
			//throw MyException("ex_obj2");
		}
		A b;
	}
/*
	catch(...)
	{
		cout<<"catch unknow exception"<<endl;
	}
*/
/*
	catch(MyException& m)
	{
		cout<<"catch exception"<<endl;
	}
*/
	catch(MyException& m)
	{
		cout<<"catch exception"<<endl;
	}
}

