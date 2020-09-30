#include <iostream>
using namespace std;
#include "node.h"

void NODE::linkTo(NODE *p)
{	
	m_next = p;	
}
NODE*& NODE::next()
{	
	return m_next;	
}

void INT::print() const
{
	std::cout << "INTEGER��" << i << std::endl;
}

void CHAR::print() const
{
	std::cout << "CHAR ��" << ch << std::endl;
}

void DOUBLE::print() const
{
	cout <<"DOUBLE��" << i << std::endl;
}

void STRING::print() const
{
	std::cout << "STRING��" << p << std::endl;
}

STRING::STRING(char *p) 
{	
   this->p = new char[strlen(p)+1]; 
   strcpy(this->p, p);
}