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
		cout << "拷贝一个MyException异常对象，名称为:ex_"<<m_name<< endl;
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

int main()
{ 
	try
	{
		A a;
		{
			// 构造一个异常对象，这是局部变量
			MyException ex_obj1("ex_obj1");

			// 这里抛出异常对象
			// 注意这时编译器会复制一个全局的异常对象，然后销毁exA_obj1，a
			throw ex_obj1;
			//throw MyException("ex_obj2");
		}
		A b;
	}	
	catch(MyException& m)  //观察去掉&
	{
		cout<<"catch exception"<<endl;
	}
	catch(...)
	{
		cout<<"catch unknow exception"<<endl;
	}
	return 0;
}

