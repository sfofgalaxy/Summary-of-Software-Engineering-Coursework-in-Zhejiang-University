#include "stdio.h"
#include "string.h"
#define MAXLEN 80
double f(int a);
void main()
{  
    char ch;
    char str[MAXLEN], num[MAXLEN];
    int i, k,a;
    int looptimes, ri;
    long number;

    scanf("%d", &looptimes);
    getchar();
    for(ri = 1; ri <= looptimes; ri++){i=0;
        while((ch = getchar()) != '\n'){
            str[i]=ch;
            i++;
        }
        str[i]=0;
        k=i;a=0;number=0;
        for(i=0;str[i]!=0;i++){
            if(str[i]<='9'&&str[i]>='0')a++;
            else if(str[i]<'G'&&str[i]>='A')a++;
            else if(str[i]<'g'&&str[i]>='a')a++; 
			else str[i]=0;	
        }
        a--;
        for(i=0;i<k;i++){
        	if(str[i]<='9'&&str[i]>='0'){
        		number+=(str[i]-48)*f(a);
        		a--;
        	}
        	else if(str[i]<'G'&&str[i]>='A'){
        		number+=(str[i]-55)*f(a);
        		a--; 
        	}
        	else if(str[i]<'g'&&str[i]>='a'){
        		number+=(str[i]-'a'+10)*f(a);
        		a--;
        	}
        }
      	printf("Dec = %ld\n",number);
    }
}
double f(int a){
	double s=1;
	int i;
	for(i=1;i<=a;i++){
		s*=16;
	}
	return s;
}
