#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(void)
{
      int loop_time,i;
      loop_time = GetInteger();
      
      for(i = 0; i < loop_time; i++)
	{
		int a=0;
			double b=0;
			int c=0;
        while(a!=-1)
        {
        	
        	scanf("%d",&a);
        	b=a+b;
        	c++;
        }
        printf("The average is %.2f",(b+1)/(c-1));
     }
      return 0;

}
