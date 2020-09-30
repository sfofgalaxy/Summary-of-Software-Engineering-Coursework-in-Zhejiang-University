#include "stdio.h"
#define MAXLEN 80
int main(void)
{	
    char cc, ch;
    char str[MAXLEN];
    int i,count;
    int looptimes, ri;

    scanf("%d", &looptimes);
    getchar();
    for(ri = 1; ri <= looptimes; ri++){
        i = 0;count=0;
    	while((str[i] = getchar( )) != '\n') 
            i++; 
    	str[i] = 0;
	cc = getchar();
	getchar();	
    for(i=0;str[i]!=0;i++){
    	if(str[i]==cc)count++;
    }
      	printf("count = %d\n", count);
   }
}

