#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"
int main(void)
{
    int flag, i, j, k, m, n;
    n=GetInteger();
    for(i=1;1<=n;i++){
    	m=GetInteger();
    	flag=0;
    	 {
    		for(j=2;j<m;j++){
    			if(m%j!=0)flag=0;else{flag=1;break;
    			}
    		}
		}
		if (m==1) printf("%d is not a prime\n", m);
    	else if(flag==0)printf("%d is a prime\n", m);
    	else printf("%d is not a prime\n", m);
    } 
}
