#include "stdio.h"
#define MAXLEN 80
int main(void)
{ 
    char cc, ch;
    char str[MAXLEN];
    int count, flag, i, index;
    int looptimes, ri;

    scanf("%d", &looptimes);
    getchar();
    for(ri = 1; ri <= looptimes; ri++){
        cc = getchar();
        getchar();
        flag=0;
        i = 0;
        while((ch = getchar()) != '\n'){
            str[i++] = ch;
        }
        str[i] = 0;
        for(i=0;str[i]!=0;i++){
        	if(cc==str[i]){
        		index=i;flag=1;
        	} 
        } 
        if(flag != 0)  
            printf("index = %d\n", index);
        else 
            printf("Not Found\n");
    }
}
