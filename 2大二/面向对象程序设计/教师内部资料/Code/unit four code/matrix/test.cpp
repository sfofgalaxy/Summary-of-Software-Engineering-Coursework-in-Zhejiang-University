#include <iostream>
using namespace std;
#include "MATRIX.h"

void main()
{	
	MATRIX<int> m1(2,3);	//MATRIX::MATRIX(int m1,int n1)
	MATRIX<int> m2(2,3);
	m1<<2<<5<<7<<4<<3<<1;	//(((m1.oeprator<<(2)).operator<<(5)).oparator<<(7))
	std::cout << m1 << std::endl;

	m2<<6<<2<<8<<5<<1<<7;
	std::cout << m2 << std::endl;

	MATRIX<int> m=m1+m2;  //MATRIX::MATRIX(m1.operator+(m2))
	std::cout << m << std::endl;
	m[1][2] = 0;	//*(m.operator[](1)+2)  a[i]===*(a+i)
	std::cout << m;	
}