#include <stdio.h>

int fmax(int,int);

void main()
{
   printf("%d", fmax(1,2,3,4));
   /*printf("%lf", lfmax(1,2,3,4));*/
}

int fmax(int x, int y)
{
	return x>y ? x : y;
}
/*
double  lfmax(int x, int y)
{
	return x>y ? x : y;
}*/