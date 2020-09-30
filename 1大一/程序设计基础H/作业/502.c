#include <stdio.h>
int main(void)
{
    int flag, i, n, t;
    int looptimes, ri;
    double item, sum;

    scanf("%d", &looptimes);
    for(ri = 1; ri <= looptimes; ri++){
        scanf("%d", &n);
        t=3*n-2;sum=0;flag=1;
        for(i=1;i<=t;i+=3){
        	sum+=flag*1.0/i;
        	flag=-flag;
        }
      	printf("sum = %.3f\n", sum);
    }
}
