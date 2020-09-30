#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
int main()
{
    float e,s;
    int i;
    
    e = 1;
    s = 1;
    i = 1;
    while(1/s >= 1e-6){
    s*=i;i++;e+=1/s;
    } 
    printf("%.9f\n",e);
    
    return 0;

}

