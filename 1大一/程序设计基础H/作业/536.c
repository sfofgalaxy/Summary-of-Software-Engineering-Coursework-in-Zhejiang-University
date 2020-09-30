#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
int main(void)
{
    int i,j;int a,b,c;
    for(i = 1; i <= 9999; i++ ){a=1;  
        for(j=2;j<i;j++){
        	if(i%j==0)a+=j;
        } 
        if(a==i&&a!=1)printf("%d\n",i);   
    }
    
    return 0; 
} 
