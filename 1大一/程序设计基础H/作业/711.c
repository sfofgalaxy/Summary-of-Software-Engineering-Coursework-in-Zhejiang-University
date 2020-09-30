#include<stdio.h>
#include<string.h>
void main()
{
    char s[80], t[80];
    int m;
    int looptimes, ri;
    void strmcpy(char *s,char *t, int m);

    scanf("%d", &looptimes);
    getchar();
    for(ri = 1; ri <= looptimes; ri++){
        gets(t);
        for(m=0;m<80;m++)s[m]=0;
        scanf("%d", &m);
        getchar();
        if(strlen(t) < m)
            printf("error input");
        else{
        strmcpy(s,t,m);
            puts(s);
        }
    }
}

void strmcpy(char*s,char*t,int m){
	int i;
	for(i=0;t[m+i-1]!=0;i++)s[i]=t[m+i-1];
}
