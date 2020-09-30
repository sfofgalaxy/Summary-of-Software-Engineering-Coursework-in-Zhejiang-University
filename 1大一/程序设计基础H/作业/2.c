#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
int sign(int x);
int main(void)
{
    int x, y;
    int looptimes, ri;

    looptimes=GetInteger();
    for(ri = 1; ri <= looptimes; ri++){
        x=GetInteger();
        y=sign(x); 
        printf("sign(%d) = %d\n", x, y);
    }
}
int sign(int x){
	int a = 0;
	if(x>0) return 1;
	else if (x<0)return -1;
	else return 0; 
}

