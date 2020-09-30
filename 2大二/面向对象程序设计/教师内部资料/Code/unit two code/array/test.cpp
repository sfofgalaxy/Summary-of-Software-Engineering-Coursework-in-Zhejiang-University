#include <iostream>
using namespace std;
#include <memory.h>
#include "Array.h"

int process(int&) 
{
	return 0;
}

double process(const int&) 
{
	return 0;
}

int main()
{
  	Array a(10);
	int j;

 	for(int i=0;i < a.getSize();i++)
		a[i] = i;	 
	process(j);

	a.print();
	const Array b;
	//b.print();
	for(int i=0;i < b.getSize();i++)
	   cout << b[i];
	//b = a;  //bitcopy
	//cout << b << endl;
	system("pause");
}