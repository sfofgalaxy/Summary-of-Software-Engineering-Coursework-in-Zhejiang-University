#include <stdio.h>
#include <math.h>
int main(void)
{
    int denominator, flag;
    int looptimes, ri;
    double eps, item, sum;

    scanf("%d", &looptimes);
    for(ri = 1; ri <= looptimes; ri++){
        scanf("%le", &eps);
        item=1;flag=1;sum=0;denominator=1;
        while(item>=eps){
        	
        	
        	item=1.0/denominator;
        	sum+=item*flag;
        	denominator+=3;
        	flag*=-1;
        } 
      	printf("sum = %.6f\n", sum);
   }
}
