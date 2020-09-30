#include <stdio.h>     
#include <string.h>
int main(void)
{
    char str[80];
    int i, s;
    int looptimes, ri;

    scanf("%d", &looptimes);
    getchar();
    for(ri = 1; ri <= looptimes; ri++){
        i = 0;s=0; 
        while((str[i] = getchar( )) != '\n') 
            i++; 
        str[i] = 0;
		for(i=0;str[i]!=0;i++){
			if(str[i]<='9'&&str[i]>='0'){
				s=s*10+str[i]-48;
			}
		}    
	printf("%d\n",s);
    }
}


