#include <cmath>
#include <cfloat>
#include "iostream"
#include "complex.h"

const complex complex::operator+(const complex& com) const
{
	complex temp(rpart+com.rpart,ipart+com.ipart);
	return temp; 
}

void complex::print() const
{
	if ((-DBL_EPSILON < ipart) && (ipart < DBL_EPSILON))
	    std::cout << rpart << std::endl;
	else if (ipart > 0)
		std::cout << rpart << "+" << ipart << 'i' << std::endl;
	else
		std::cout << rpart << "-" << -ipart << 'i' << std::endl;
}

const complex complex::operator+() const
{
	return complex(+rpart,+ipart);
}

//non-member function, global function
const complex operator+(int i, const complex& obj)
{
	complex temp(i+obj.rpart, obj.ipart);
	return temp;
}