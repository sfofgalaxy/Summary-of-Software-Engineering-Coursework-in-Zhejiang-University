#include <cassert>
#include <iostream>
using namespace std;

class A 
{
public:
	virtual void print() = 0;
};

class B:public A   
{
public:
	virtual void print()
	{ 
		cout << "I am B." << endl;
	}
	void f()
	{
		cout << "I am a function of B,but isn't a virtual" << endl;
	}
};

class C:public B 
{
public:
	virtual void print()
	{ 
		cout << "I am C." << endl;
	}
	void f()
	{
		cout << "I am a function of C,but isn't a virtual" << endl;
	}
};

class D:public C 
{
public:
	virtual void print()
	{ 
		cout << "I am D." << endl;
	}
	void f()
	{
		cout << "I am a function of D,but isn't a virtual" << endl;
	}
};

void main()
{
	//A a;
	A *p;//����ָ��
	p = new D;//upcasting
   	p->print();  //dynamic binding
	//p->f();      //static binding  compile-time error
	
	//(D*)p->f();//ǿ��ת��, downcast�����ǰ�ȫ��
	//(C*)p->f();

    /*��C++ �У����ֹdowncast ����Ŀ���Σ�U����ʽ�в�ԓ��C-style 
	�����D��,��횸���dynamic_cast �D���\����
	*/
	D *pd = dynamic_cast<D*>(p);
    if (pd != NULL)
        pd->f();
}