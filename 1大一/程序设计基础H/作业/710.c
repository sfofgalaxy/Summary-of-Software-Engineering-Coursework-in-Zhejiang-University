/*程序填空，不要改变与输入输出有关的语句。
输入一个正整数 looptimes (0<looptimes<10)，做 looptimes 次下列运算：
输入一个字符串 str，再输入一个字符 c，将字符串 str 中出现的所有字符 c 删除。
要求定义并调用函数delchar(str,c), 它的功能是将字符串 str 中出现的所有 c 字符删除，函数形参str的类型是字符指针，形参c的类型是char，函数类型是void。
输入输出示例：括号内为说明
输入
3               (looptimes=3）
happy new year  (字符串"happy new year")
a               (待删除的字符'a')
bee             (字符串"bee")
e               (待删除的字符'e')
111211          (字符串"111211")
1               (待删除的字符'1')
输出
result: hppy new yer    (字符串"happy new year"中的字符'a'都被删除)
result: b               (字符串"bee"中的字符'e'都被删除)
result: 2               (字符串"111211"中的字符'1'都被删除)*/
#include<stdio.h>
void main()
{
    char c;
    char str[80];
    int looptimes, ri;
    void delchar(char *str, char c);
    int i;
    scanf("%d", &looptimes);
    getchar();
    for(ri = 1; ri <= looptimes; ri++){
    	for(i=0;i<80;i++)str[i]=0;
        gets(str);
        scanf("%c", &c);
        getchar();
        delchar(str,c);
        printf("result: ");
        puts(str);
    }
}

void delchar(char *str, char c)
{
	int j,k;
   for(j=k=0;str[j]!='\0';j++) 
    if(str[j]!=c) 
      str[k++]=str[j]; 
    str[k]='\0'; 
}

