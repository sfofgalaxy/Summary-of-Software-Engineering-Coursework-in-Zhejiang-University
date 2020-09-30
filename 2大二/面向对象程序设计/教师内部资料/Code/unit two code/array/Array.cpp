#include <iostream>
using namespace std;
#include <memory.h>
#include "Array.h"

istream& operator>>(istream& in, Array& ob)
{
   for(int i=0; i<ob.size; i++)
	   in >> ob[i];

   return in;   //为便于cin>>ob1>>ob2;所返回in本身
}

ostream& operator<<(ostream& out, const Array& ob)
{
	for (int i=0; i<ob.size; i++)
		out << ob[i] << ","; //because ob is a const,so ob.operator[](i) must be const function

	out << endl;
	return out;
}

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

void Array::print()
{
	for ( int i = 0; i < size; i++ )
	    cout << p[i] << "\t";
    cout << endl;
}
/*
void Array::print() const
{
	for ( int i = 0; i < size; i++ )
	    cout << p[i] << "\t";
    cout << endl;
}*/

int Array::getSize() const
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
	    //return 3; //can't return a const 
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