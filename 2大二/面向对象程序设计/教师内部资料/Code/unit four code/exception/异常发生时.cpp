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
		cout << "����һ��MyException�쳣��������Ϊ:"<<m_name<< endl;
	}

	MyException(const MyException& old_e)
	{
		m_name = old_e.m_name;
		cout << "����һ��MyException�쳣��������Ϊ:ex_"<<m_name<< endl;
	}
	MyException& operator= (const MyException& old_e)
	{
		m_name = old_e.m_name;
		cout << "��ֵ����һ��MyException�쳣��������Ϊ:"<<m_name<< endl;
		return *this;
	}

	virtual ~ MyException () 
	{
		cout << "����һ��MyException�쳣��������Ϊ:" <<m_name<< endl;
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
			// ����һ���쳣�������Ǿֲ�����
			MyException ex_obj1("ex_obj1");

			// �����׳��쳣����
			// ע����ʱ�������Ḵ��һ��ȫ�ֵ��쳣����Ȼ������exA_obj1��a
			throw ex_obj1;
			//throw MyException("ex_obj2");
		}
		A b;
	}	
	catch(MyException& m)  //�۲�ȥ��&
	{
		cout<<"catch exception"<<endl;
	}
	catch(...)
	{
		cout<<"catch unknow exception"<<endl;
	}
	return 0;
}

