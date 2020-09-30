#include <stdio.h>

int twoIntegerMax(int,int);

void main()
{
   printf("%d", twoIntegerMax(1,2,3,4));
   //printf("%lf", twoDoubleMax(1.1, 2.2));
}

int twoIntegerMax(int x, int y)
{
	return x>y ? x : y;
}
/*
double  twoDoubleMax(double x, double y)
{
	return x>y ? x : y;
}*/