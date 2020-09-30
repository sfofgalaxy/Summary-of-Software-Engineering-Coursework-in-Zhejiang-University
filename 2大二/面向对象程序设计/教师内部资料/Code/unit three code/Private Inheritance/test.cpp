#include "intlist.h"
#include "intstack.h"
#include <iostream>

void main()
{
	intlist a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.append(4);
	a.append(5);
	a.append(6);
	a.print(); 

	intstack b;
	b.push(1);
	b.push(2);
	b.push(3);
	//b.append(4);
	std::cout << b.pop() << std::endl;
	std::cout << b.pop() << std::endl;
	std::cout << b.pop() << std::endl;
}








