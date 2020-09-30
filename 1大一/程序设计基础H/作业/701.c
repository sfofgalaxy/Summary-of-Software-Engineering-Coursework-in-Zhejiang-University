#include <stdio.h> 
int main(void)
{
    int i, j, temp;
    char str[80];		

    i = 0;
    while((str[i] = getchar( )) != '\n') 
        i++; 
    str[i] = 0;
    for(j=0;j<i/2;j++){
    	temp=str[j];
    	str[j]=str[i-j-1];
    	str[i-j-1]=temp;
    }
    for(i = 0; str[i] != 0; i++) 
        putchar(str[i]);
}
