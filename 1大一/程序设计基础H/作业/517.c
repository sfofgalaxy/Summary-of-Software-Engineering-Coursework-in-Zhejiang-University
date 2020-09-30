#include <stdio.h>
int main(void)
{
    int digit, in, power, temp;
    int looptimes, ri;
    int i,a,b;
    scanf("%d", &looptimes);
    for(ri = 1; ri <= looptimes; ri++){
        scanf("%d", &in);
        if(in<0)in=-in;digit=0;power=in;
        do{
        	digit++;
        	power/=10;
        }while(power>0);a=1;
        for(i=2;i<=digit;i++){
        	a*=10; 
        }
        for(i=1;i<=digit;i++){
        	printf("%-2d", in/a);
        	in%=a;a/=10;
        }
     	printf("\n");
   }
}
