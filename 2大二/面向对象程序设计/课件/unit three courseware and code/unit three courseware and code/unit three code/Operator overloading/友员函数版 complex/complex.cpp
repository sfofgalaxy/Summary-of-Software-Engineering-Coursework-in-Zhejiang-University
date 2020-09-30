#include <iostream>
#include <cmath>
#include <cfloat>
using namespace std;
#include "complex.h"
/*
//non-member function(global function) x+y ==> operator+(x, y)
const complex operator+( const complex& add1, const complex& add2)  //add2是加数，add1是被加数
{
	complex temp;
	temp.setReal(add1.getReal()+add2.getReal());
	temp.setImaginary(add1.getImaginary()+add2.getImaginary());
    return temp;
}*/

//friend global function x+y ==> operator+(x, y)
const complex operator+( const complex& x, const complex& y)  //y是加数，x是被加数
{
	complex temp(x.rpart + y.rpart, x.ipart + y.ipart);
    return temp;
}
//+a operator+(a)
const complex operator+(const complex& x)
{
	complex temp(+x.rpart, +x.ipart);
	return temp;
}

//cout << a ==> operator<<(cout, a)
//cout << a << b  ==> operator<<( operator<<(cout,a),b );
ostream& operator<<(ostream& os, const complex& com)
{
    os << "(" << com.rpart;
	if (!((-DBL_EPSILON < com.ipart) && (com.ipart < DBL_EPSILON)))
		os << "," << com.ipart << "i";
	os << ")" << endl;
	return os;
}

istream& operator>>(istream& is, complex& com)
{
	is >> com.rpart >> com.ipart;
	return is;
}
/*
A m;
cin >> m;
istream& operator>>(istream& is, A& com)
{
	??;
	return is;
}
*/