#include "stdio.h"
int main(void)
{
    int i, j, n;
    int looptimes, ri;
    double e, product;

    scanf("%d", &looptimes);
    for(ri = 1; ri <= looptimes; ri++){
        scanf("%d", &n);
        e=0;product=1;
        for(i=1;i<=n;i++){
        	product=1;
        	for(j=1;j<=i;j++){
        		product*=j;
        	}
        	e+=1/product;
        }
    	printf("e = %0.4f\n", e);
  }
}
