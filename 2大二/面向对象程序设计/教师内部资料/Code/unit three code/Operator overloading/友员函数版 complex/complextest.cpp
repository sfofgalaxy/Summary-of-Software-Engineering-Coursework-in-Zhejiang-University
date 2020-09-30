#include <iostream>
#include <cmath>
using namespace std;
#include "complex.h"

int main()
{
	complex a(11.1,22.2),b(33.3,44.4);
	const complex d(0.1,0.2);
    complex c;

    cout << a << b;

	c = a + b;    //Compiled: operator+(a,b)
	cout << c;

	c = b + a;    //Compiled: operator+(b,a)
	cout << c;

	c = a + b + d; //operator+(operator+(a,b),d)
	cout << c;

	c = +d + b;//operator+(operator+(d),b)
	cout << c;

	c = a * b;

	c = a + 4;  //operator+(a, complex(double(4), 0.0)); OR a.operator double() + 4
	cout << c;

	c = 4 + a;	  //operator+(complex(double(4), 0.0),a)
	cout << c;
	
	a = 4 + 4;
	cout << a;

	return 0;
}
