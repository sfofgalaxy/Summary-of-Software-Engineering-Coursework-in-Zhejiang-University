#include <stdio.h>
void main()
{
    char s[80]={'\0'};
    int looptimes, ri;
    int mirror(char *p);
    
    scanf("%d", &looptimes);
    getchar();
    for(ri = 1; ri <= looptimes; ri++){
        gets(s);
        if(mirror(s) != 0)
      	    printf("YES\n");
        else
            printf("NO\n");
    }
}

int mirror(char *p){
	int i;
	int a;
	for(a=0;p[a]!=0;a++);
	for(i=0;i<a/2;i++){
		if(p[i]!=p[a-i-1])return 0;
	}
	return 1;
	  
	
} 

