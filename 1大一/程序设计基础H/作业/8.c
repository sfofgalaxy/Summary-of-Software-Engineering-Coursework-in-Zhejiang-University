#include "stdio.h"
#include "math.h"
#include "genlib.h"
#include "simpio.h"

double funcos(double e, double x);
int main(void)
{
    int looptimes, ri;
    double e, sum, x; 
    
    looptimes=GetInteger();
    for(ri = 1; ri <= looptimes; ri++){
       e=GetReal();
       x=GetReal();
       sum=funcos(e,x);
        printf("sum = %f\n", sum);
    }
}
double funcos(double e, double x){double a=1;double i=0;double c=0;int flag=1;
	while(e<=a){double p;
		a=pow(x,i);
		for(p=1;p<=i;p++){
			a=a/p;
		}
		i+=2;
		c+=flag*a;
		flag=-flag;
	}
	return c;
}

