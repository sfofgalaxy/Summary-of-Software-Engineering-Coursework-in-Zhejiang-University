#include <stdio.h>
#include <string.h>
int main(void)
{
    char sx[80], longest[80];
    int i, n,j,k;
    int looptimes, ri;
    int a,b;

    scanf("%d", &looptimes);
    for(ri = 1; ri <= looptimes; ri++){
    	for(i=0;i<80;i++)sx[i]=0;
    	for(i=0;i<80;i++)longest[i]=0;
        scanf("%d", &n);
        scanf("%s", longest);
        for(j=0;longest[j]!='\0';j++);
    for(i=1;i<n;i++){
      scanf("%s",sx);
      
      for(k=0;sx[k]!='\0';k++);
      if(k>j){
      	for(a=0;a<k;a++)longest[a]=sx[a];
      j=k;
      }
    } 
    printf("The longest is: %s\n",longest);
} 
}


