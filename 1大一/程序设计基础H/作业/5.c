#include "stdio.h"
#include "math.h"
#include "genlib.h"
#include "simpio.h"

int main(void)
{
    int count, i, m, n, sum;
    int looptimes, ri;
    int prime(int m);
    looptimes=GetInteger();
    for(ri = 1; ri <= looptimes; ri++){
         m=GetInteger();
         n=GetInteger();
         count=0;sum=0;
         for(i=m;i<=n;i++){
		 {if(i==1)continue;
         else if(prime(i)==0){
         	sum+=i;count++;
         
         }}
        }printf("Count = %d, sum = %d\n", count, sum);}
    }

int prime(int m){
	int a ,b=0;
	for(a=2;a<m;a++){if(m%a!=0)b=0;else {b=1;break;
	}}
	return b;
	
}
