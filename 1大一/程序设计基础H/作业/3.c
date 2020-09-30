#include "stdio.h"
#include "math.h"
#include "genlib.h"
#include "simpio.h"
int main(void)
{
    int count, i, j, k, m, n;
    int ri,looptimes;
  
   looptimes=GetInteger();
   for(ri = 1; ri <= looptimes;ri++){count=0; 
         m=GetInteger();
         n=GetInteger();
        printf("primes:\n");
        for(i=m;i<=n;i++)
		{k=0;
		if(m==1)
		  {m++;
		  }
		  else
		  {	for(j=2;j<i;j++)
		       {if(i%j!=0)k=0;else {k=1;break;}}
			   if(k==0&&count<=5){printf("%d ",i);count++;}
			   else if(k==0&&count==6){printf("\n%d ",i);count=1;}
          }
		
	
    }
}}
