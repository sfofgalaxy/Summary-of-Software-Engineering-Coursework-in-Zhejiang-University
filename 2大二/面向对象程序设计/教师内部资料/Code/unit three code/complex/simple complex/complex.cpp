/* 版本说明*/

#include "complex.h"
#include <iostream>
#include <cfloat>

complex::complex()
{
	real_part = 0;
	imaginary_part = 0;
}


complex::complex(double r)
{
	real_part = r;
	imaginary_part = 0;
}

complex::complex(double real,double imag)
{
	real_part = real;
	imaginary_part = imag;
}

void complex::print() 
{
	/*if ( imaginary_part == 0.0) //浮点数不能进行==比较
	      std::cout << real_part << std::endl;
	  else
	      std::cout << real_part << "+" << imaginary_part << 'i' << std::endl;
	*/
	if ((-DBL_EPSILON < imaginary_part) && (imaginary_part < DBL_EPSILON))
		std::cout << real_part << std::endl;
	else if (imaginary_part > 0)
		std::cout << real_part << "+" << imaginary_part << 'i' << std::endl;
	else
		std::cout << real_part << "-" << -imaginary_part << 'i' << std::endl;
}

void complex::set_real(double rpart)
{
	real_part = rpart;
}
void complex::set_imaginary(double ipart) 
{
	imaginary_part = ipart;
}
double complex::get_real()
{
	return real_part;
}
double complex::get_imaginary()
{
	return imaginary_part;
}

complex& complex::operator =(const complex& com)
{
	real_part=com.real_part;
    imaginary_part=com.imaginary_part;
	return *this;
}