/*程序填空，不要改变与输入输出有关的语句。
输入5个字符串，输出其中最大的字符串。
输入输出示例：括号内为说明
输入：
peach 
pear
melon
orange
berry
输出：
Max is: pear*/
#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[80], max[80];
    int i;
    int a;
    scanf("%s", max);
    for(i=1;i<=4;i++){
    	
    	scanf("%s", str);
    if(strcmp(str,max)>0)
       for(a=0;a<80;a++)max[a]=str[a];
    	
    }
    printf("Max is: %s\n", max);
}
