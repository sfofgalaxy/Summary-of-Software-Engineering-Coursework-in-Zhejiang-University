#include <stdio.h>
int main(void)
{
    char sign;
    int x, y; 
    int looptimes, ri;

    scanf("%d",&looptimes);
    for(ri = 1;ri <= looptimes; ri++){
        scanf("%d%c%d", &x, &sign, &y);
        switch(sign){
        	case '*':printf("%d * %d = %d\n", x, y, x * y);break;
        	case '/':printf("%d / %d = %d\n", x, y, x / y);break;
        	case '%':printf("%d Mod %d = %d\n",x, y, x % y);break;
        	default:printf("Invalid operator\n");break;
        }
    }
}

