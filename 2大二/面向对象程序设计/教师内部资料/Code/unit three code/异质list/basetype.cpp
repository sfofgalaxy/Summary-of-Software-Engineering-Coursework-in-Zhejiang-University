#include <iostream>
using namespace std;
#include "basetype.h"

void TYPE::linkTo(TYPE *p)
{	
	m_next = p;	
}
TYPE*& TYPE::next()
{	
	return m_next;	
}

void INT::print() const
{
	std::cout << "INTEGER£º" << i << std::endl;
}

void CHAR::print() const
{
	std::cout << "CHAR £º" << ch << std::endl;
}

void DOUBLE::print() const
{
	cout <<"DOUBLE£º" << i << std::endl;
}

void STRING::print() const
{
	std::cout << "STRING£º" << p << std::endl;
}

STRING::STRING(char *p) 
{	
   this->p = new char[strlen(p)+1]; 
   ::strcpy(this->p, p);
}