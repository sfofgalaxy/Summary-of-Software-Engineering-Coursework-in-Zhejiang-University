#include "complex.h"
#include <iostream>

int main()
{
	complex a(1.1);   //call complex(1.1, 0.0)
	complex b(2.2,3.3);  //call complex(2.2, 3.3)
	complex c;        //call complex(0.0, 0.0)

	a.print();
	b.print();
	c.print();

	return 0;
}