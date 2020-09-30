#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int even(int n);
int main(void)
{
    int n, sum=0;
    int ri, looptimes;
   
   looptimes=GetInteger();
    for(ri = 1; ri <= looptimes; ri++){	
        n=GetInteger();
        while(n>0){
        	if(even(n)==0) sum+=n;
        scanf("%d",&n);} 
        printf("The sum of the odd numbers is %d.\n", sum);
   
   }
}
int even(int n){
	if(n%2!=0) return 0;else return 1; 
}

