#include "counter.h"

//Prefix ++a: return incremented object
counter& counter::operator++()	
{ 	
	if (59 == second)
    	second = 0;
	else
		second += 1;
	
	return *this;
}

//Postfix a--: return the seconds before increment
int counter::operator++(int) 
{		
	int t = second;
	if (59 == second)
    	second = 0;
	else
		second += 1;
	
	return t;
}

counter& counter::operator--()	
{ 	
	if (0 == second)
    	second = 59;
	else
		second -= 1;
	
	return *this;
}

int counter::operator--(int) 
{
	int t = second;
	if (0 == second)
    	second = 59;
	else
		second -= 1;
	
	return t;
}
