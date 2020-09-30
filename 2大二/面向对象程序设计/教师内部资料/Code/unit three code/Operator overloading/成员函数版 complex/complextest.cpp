#include <iostream>
#include "complex.h"

int main()
{
	complex a(11.1,22.2), b(33.3,44.4);
	complex c;

    a.print(); 
	b.print();
	c.print();
	c = a + b;  //�����������: a.operator+(b)
	c.print();
	c = b + a;//������
	c.print();
	c = a + b + c;
	//�����(a.operator+(b)).operator+(c)
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
	//��Ҫ֧�ֻ�����Ͳ��������磬complexҪ�ܺ�int/float/double��ϲ�����
 	c = a + 4;  //c = a.operator+(complex(double(4)));
	c.print();
    c = 4 + a; //complie-time error
	//c = 4 + 4;
	return 0;
}