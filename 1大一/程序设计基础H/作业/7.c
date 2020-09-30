#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
double fact(int n);
int main(void)
{    
    int i, m;
    double sum; 
   sum=0;
    m=GetInteger();
    for(i=1;i<=m;i++){
    	sum+=fact(i);
    }
    printf("1!+2!+...+%d! = %f\n", m, sum); 
}

double fact(int n){
	int a;
	double b=1;
	for(a=1;a<=n;a++)b*=a;
	return b;
}
