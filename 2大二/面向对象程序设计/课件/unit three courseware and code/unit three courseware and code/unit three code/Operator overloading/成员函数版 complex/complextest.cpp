#include <iostream>
#include "complex.h"

int main()
{
	complex a(11.1,22.2), b(33.3,44.4);
	complex c;

    a.print(); 
	b.print();
	c.print();
	c = a + b;  //编译器翻译成: a.operator+(b)
	c.print();
	c = b + a;//交换律
	c.print();
	c = a + b + c;
	//结合律(a.operator+(b)).operator+(c)
    c.print();

    //a + b = c;

	const complex m(1.1,2.2);
	c = +a;    //a.operator+()
	c.print();
	c = +m;  
	c.print();
    //c = ++a;  
	//c = +(+a);
	//c.print();
    c = +a + b;	//(a.operator+()).operator+(b)
	c = a + +b;
	c.print();
	//还要支持混合类型操作，比如，complex要能和int/float/double混合操作。
 	c = a + 4;  //c = a.operator+(complex(double(4)));
	c.print();
    c = 4 + a; //complie-time error
	//c = 4 + 4;
	return 0;
}