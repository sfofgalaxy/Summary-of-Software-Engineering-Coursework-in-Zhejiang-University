#include <iostream>
using namespace std;
#include "GenericStack.h"

int main()
{	
	//STACK t;//error
	STACK<int> s(10);//模板实例化，类实例化	
	STACK<double> m(10);
	//STACK<complex> a(20);
	//a.push(m);
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s;
//	cout<<s.getsize()<<"  "<<s.pop()<<s.pop()<<s.pop()<<endl;
	int a=s.pop();
	int b=s.pop();
	int c=s.pop();
	cout<<s.getsize()<<"  "<<a<<b<<c<<endl;
	

	return 0;
}

