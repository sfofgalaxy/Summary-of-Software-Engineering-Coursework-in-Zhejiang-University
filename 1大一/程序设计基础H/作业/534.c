#include <stdio.h>
#include "math.h"
#include "genlib.h"
#include "simpio.h"

int main(void)
{
    int looptimes, ri,i;
    int num;
    int a ,b,c;
    looptimes = GetInteger();
    for(ri = 1; ri <= looptimes; ri++){
        num = GetInteger();
        a=num;printf("%d=",num) ;
        while(a>1){ 
        	for(i=2;i<=a;i++){
        		if(a%i==0&&a!=i){
				printf("%d*",i);a/=i;i=1;}
				else if(a==i){
        		printf("%d",i);a/=i;}
        	}
        }
      	printf("\n");
    }
    
    return 0;
}  

