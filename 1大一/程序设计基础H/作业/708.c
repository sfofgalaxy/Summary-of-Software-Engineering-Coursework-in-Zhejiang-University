/*������գ���Ҫ�ı�����������йص���䡣
����5���ַ�����������������ַ�����
�������ʾ����������Ϊ˵��
���룺
peach 
pear
melon
orange
berry
�����
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
