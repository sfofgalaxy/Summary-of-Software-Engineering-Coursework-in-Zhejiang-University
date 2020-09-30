#include "stdio.h"
int main(void)
{
    int i, digit, m, n, number, sum;
    int looptimes, ri;
     int a ,b;
    scanf("%d",&looptimes);
    for(ri = 1; ri <= looptimes; ri++){
        scanf("%d%d", &m, &n);
        printf("result:\n");
        number=m;
        for(number=m;number<=n;number++){
        	 digit=0;a=number;sum=0;
        do{
        	number/=10;
        	digit++;
        }while(number>0);number=a;
        for(i=1;i<=digit;i++){
        	b=a%10;a/=10;
        	sum+=b*b*b;
        }
        if(sum==number)printf("%d\n", number);
        	
        }
       
    }
}

