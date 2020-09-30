#include <stdio.h>
#include <string.h>
int max_len(char *s[],int n);
void main()
{
	int i,n;
	char s[10][80],*p[10];

	scanf("%d",&n);getchar();
	for(i=0;i<n;i++){
		gets(s[i]);
		p[i]=s[i];
	}
	printf("length=%d\n",max_len(p,n));
}
int max_len(char *s[],int n){
	int a,b;int i;
	a=strlen(s[0]);
	for(i=1;i<n;i++){
		b=strlen(s[i]);
		if(a<b)a=b;
	} 
	return a;
}

