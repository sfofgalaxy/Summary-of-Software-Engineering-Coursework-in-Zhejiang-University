#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
int main(void)
{    
    int a, b, maximum;
    int looptimes, ri;
    int max(int a, int b);
   
    looptimes=GetInteger();

    for(ri = 1; ri <= looptimes; ri++){
        a=GetInteger();
        b=GetInteger();
        maximum=max(a,b);
        printf("max(%d,%d) = %d\n", a, b, maximum);
    }
}
int max(int a , int b){
	if(a>=b)return a ;
	else return b;
}
