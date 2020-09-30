#include <iostream>
#include <string>
using namespace std;

struct A{  //sizeof(A)  8
	char ch;
	int i;
	void  display() const
	{
		cout << ch << "\t" << i << endl;
	}
};

struct B{
	int i;  //sizeof(B)  8
	char ch;
	void display() const
	{
		cout << i << "\t" << ch << endl;
	}
};

void main()
{ 
	//通过对象名直接访问
	A a;
	a.ch = 'a';
	a.i = 11;
	a.display();
	B b;
	b.ch = 'a';
	b.i = 11;
	b.display();

	//通过对象指针间接访问
	A *pa = &a;
	pa->display();
	B * pb = &b;
	pb->display();

	//不相同类型指针不可以直接赋值
    pa = &b;  //or pb = pa;

  	//任何类型指针都可以强制类型转换
	//pa = (A*)pb;  //编译通过，语义错误
	//pa->display();  //A::display()
	//pa = static_cast<A*>(pb);  //compile-time error
}