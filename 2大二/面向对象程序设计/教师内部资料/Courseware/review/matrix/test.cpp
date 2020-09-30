#include "matrix.h"

void main()
{
	Matrix m1(2,3);	//Matrix::Matrix(int m1,int n1)
	Matrix m2(2,3);
	m1<<2<<5<<7<<4<<3<<1;	//(((m1.oeprator<<(2)).operator<<(5)).oparator<<(7))
	cout<<m1<<endl;				//ostream & operator<<(cout,m1)
	m2<<6<<2<<8<<5<<1<<7;
	cout<<m2<<endl;
	Matrix m=m1+m2;  //Matrix::Matrix(m1.operator+(m2))
	cout<<m<<endl;
	m[1][2]=0;	//*(m.operator[](1)+2)  a[i]===*(a+i)
	cout<<m;
}