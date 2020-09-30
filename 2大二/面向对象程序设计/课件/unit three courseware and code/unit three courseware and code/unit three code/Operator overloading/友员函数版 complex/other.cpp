#include <iostream>
#include <cmath>
#include "complex.h"
using namespace std;

ostream& operator<<(ostream& out, const complex& obj)
{
	out << obj.rpart;
	return out;
}