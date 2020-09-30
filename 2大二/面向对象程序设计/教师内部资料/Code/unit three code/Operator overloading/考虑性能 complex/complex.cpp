#include "complex.h"
#include "iostream.h"

const complex complex::operator+( const complex& x)
{
//	complex temp(rpart+x.rpart,ipart+x.ipart);
//	return temp;
	return complex(rpart+x.rpart,ipart+x.ipart);
}


const complex operator+( int i, const complex& y)  //y是加数，x是被加数
{
    return complex(i+y.rpart,y.ipart);
}

const complex operator+( const complex& y, int i)//友员函数版
{
	return complex(i+y.rpart,y.ipart);
}

/*
complex& complex::operator+=(const complex& x)
{
    rpart += x.rpart;
    ipart += x.ipart;
	return *this;
}*/


ostream& operator<<(ostream& os, const complex& com)
{
    os << "(" << com.rpart;
	if(com.ipart)
		os << "," << com.ipart << "i";
	os << ")" << endl;
	return os;
}


istream& operator>>(istream& is, complex& com)
{
	is >> com.rpart >>com.ipart;
	return is;
}


