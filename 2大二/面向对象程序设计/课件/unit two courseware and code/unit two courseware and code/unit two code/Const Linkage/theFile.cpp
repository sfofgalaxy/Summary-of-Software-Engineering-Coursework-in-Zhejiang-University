#include "constant.h"

int i = 10;  //definition, external linkage
static int k; //definition, internal linkage

const int size = 10;   //internal linkage

extern const int L = 100;	 //external linkage

int a[size];

void fun()
{
	i = 0 + MAX + size;
	k = 1;
	k = L;
}