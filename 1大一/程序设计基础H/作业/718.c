#include <stdio.h>
#include <string.h>
char *str_cat(char *s,char *t);
void main()
{
	char s[80]={0},t[80]={0};
	gets(s);
	gets(t);
	puts(str_cat(s,t));
}
char *str_cat(char *s,char *t){
	int a,b;int i=0;
	for(a=0;s[a]!=0;a++);
	for(;t[i]!=0;i++){
		s[a]=t[i];a++;
	}
	return s;
}

