#include "complex.h"
#include <iostream>

int main()
{
	complex a(1.1,1.2);
	complex c;
	c  = a + (-1);

	a.print();
	return 0;
}