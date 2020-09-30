#include <iostream>
using namespace std;
class A{
private: 
	int x,y;
public:  
	A(): x(0), y(0)  //default constructor
	{}
    A(int x1,int y1): x(x1), y(y1)
	{}              
};

class B{
private: 
	float z;
	A m;	       //member object  
public: 
	B(int r1,int r2,float r3):m(r1,r2),z(r3)
	{}
 /*
    B(int r1,int r2,float r3):m(r2,r3),z(r1)
	{}
*/ 
	B(): m(), z(0) //m()语法上可以省略 
	{}
	/*
	B(float r):z(r)
	{}*/
};


void main()
{
	B b;  //b has a subobject: b.m
	B c(4,5,6.6);
}