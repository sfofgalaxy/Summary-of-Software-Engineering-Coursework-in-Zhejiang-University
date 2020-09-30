#include "array.h"
#include <iostream>
using namespace std;
#include <memory.h>

Array::Array(int size) : size( size ), p(new int[size])  
{
	/*
	this->size = size;
	p = new int [size]; */
	memset(p, 0, size * sizeof ( int ) );
}

Array::~Array()
{
	delete[] p;
}
/*
void Array::print() 
{
	for ( int i = 0; i < size; i++ )
	      cout << p[i] << "\t";
    cout << endl;
}*/

void print()  const   // const function member
{
	for ( int i = 0; i < size; i++ )
	      cout << p[i] << "\t";
    cout << endl;
}
int Array::get_size() const
{
	return size;
}
	
int& Array::operator[]( const unsigned i ) 
{
	if( i >= size || i < 0)
	{
		cout << "suffix is beyond the mark." << endl;
		exit(0);
	}
	else
		return p[i];  //*(p+i)
	    //return 3; can't return a const 
}
	
int Array::operator[](const unsigned i) const
{
	if( i >= size || i < 0)
	{
		cout << "suffix is beyond the mark." << endl;
		exit(0);
	}
	else
	{
		return p[i]; // *(p+i);
	}
}