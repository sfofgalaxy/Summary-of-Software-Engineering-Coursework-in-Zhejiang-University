#include "complex.h"
#include <iostream>

class  A{
	int i;
public:
	void print() {
		std::cout << i;
	} 
};

void f()
{
	A m;      //call A()
	A n[10];  //call 10 times A()
}

int main()
{
	complex a(1.1);     //call complex(double)
	complex b(2.2,3.3); //call complex(double,double)
	complex c;          //call complex()
	
	//a.real_part = 1.2;  //private data member
    double *p = (double*)&a;
    *p = 1.2;

	a.print();
	b.print();
	c.print();

	return 0;
}