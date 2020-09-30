#include <stdio.h>
#include <math.h>
int main(void)
{
    int i;
    int looptimes, ri;
    double item, s, x; 
    double fact(int n);

    scanf("%d", &looptimes);
    for(ri = 1; ri <= looptimes; ri++){s=0;
        scanf("%lf", &x);i=1;item=x;
        while(item>=0.00001){
        	item=pow(x,i)/fact(i);
        	i++;
        	s+=item;
        }
      	printf("s = %.2f\n", s);
    }
}

double fact(int n){
	int i;double sum=1;
	for(i=1;i<=n;i++){
		sum*=i;
	}
	return sum;
}
