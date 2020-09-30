#include <stdio.h>
int main(void)
{
    int gcd, lcm, m, n;  
    int looptimes, ri;  
    int c ,d ;
    int a,b;
    scanf("%d", &looptimes);
    for(ri = 1; ri <= looptimes; ri++){
        scanf("%d", &m);
        scanf("%d", &n);c=m;d=n;
        if(m <= 0 || n <= 0)
            printf("m <= 0 or n <= 0");
        else{	if(m>n){a=m;m=n;n=a;
        	}b=n;
        	if(m==n){
        		lcm=gcd=m;
        	}
			else {while(b>0){
        	
        	if(b<m){a=m;m=b;b=a;
        	}
        	b=b%m;
        	gcd=m;
        }
			}
        lcm=c*d/gcd;
            printf("%d is the least common multiple of %d and %d, %d is the greatest common divisor of %d and %d.\n", lcm, c, d, gcd, c, d);
        }
    }
}
