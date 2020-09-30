#include <iostream>
using namespace std;

class A {
public:
	A(){cout<<"A()"<<endl;}
	virtual void fun() {
		cout << "A's fun()" << endl;
		show();		
	}
	virtual void show() {
		cout << "A's show()" << endl;
	}
};

class B: public A {
public:
	B(){cout<<"B()"<<endl;}
	virtual void fun() {
		cout << "B's fun()" << endl;
		A::fun();
	}
	virtual void show() {
		cout << "B's show()" << endl;
	}
};

int main() {
	B bobj;
	A *aptr = &bobj;
	bobj.fun();
	aptr->fun();
	return 0;
}
/*
考察的知识点：virtual function member
难易度：中
Key
A()                               //0.5 points
B()                                //0.5points
B's fun()                       //0.5 points
A's fun()                       //0.5 points
B's show()                    //0.5 points
B's fun()                       //0.5 points
A's fun()                       //0.5 points
B's show()                    //0.5 points
*/