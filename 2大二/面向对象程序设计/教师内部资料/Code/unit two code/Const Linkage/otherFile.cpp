#include "constant.h"
#include <iostream>

extern int i;  //declaration
//extern const int size;

extern const int L;	 //declaration

void fun();

int main()
{
	std::cout << i + MAX << std::endl;
	//std::cout << i + MAX + size << std::endl;
	std::cout << L << std::endl;
	fun();
	return 0;
}


