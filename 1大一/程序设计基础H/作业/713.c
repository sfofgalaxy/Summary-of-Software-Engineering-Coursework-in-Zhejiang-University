#include<stdio.h>
void main()
{
    char s[80]={0};
    int i;
    int blank, digit, lower, other, upper;

    gets(s);
    upper = lower = blank = digit = other = 0;
    for(i=0;s[i]!=0;i++){
    	if(s[i]<='9'&&s[i]>='0')digit++;
    	else if(s[i]<='Z'&&s[i]>='A')upper++;
    	else if(s[i]<='z'&&s[i]>='a')lower++;
    	else if(s[i]==' ')blank++;
    	else other++;
    }
	printf("upper: %d lower: %d blank: %d digit: %d other: %d\n", upper, lower, blank, digit, other);
}
