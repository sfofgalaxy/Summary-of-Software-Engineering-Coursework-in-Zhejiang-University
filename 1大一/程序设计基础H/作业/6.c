#include "stdio.h"
#include "genlib.h"
#include "simpio.h"
int main(void)
{
    int i, m, n;
    int looptimes, ri;
    int is(int number); 
  
    looptimes=GetInteger();
    for(ri = 1; ri <= looptimes; ri++){
         m=GetInteger();
         n=GetInteger();
        printf("result:\n");
        for(i=m;i<=n;i++){if(is(i)==1)printf("%d\n", i);
        	
        }
        
    }
}

int is(int number){
	int a=number,b=0,c;
	while(a>0){c=a%10;
		a /=10;b+=c*c*c;
	}
	if(b==number)return 1;
	else return 0;
}
