/*程序填空，不要改变与输入输出有关的语句。
输入一个正整数looptimes (0<looptimes<10)，做looptimes次下列运算：
定义一个指针数组将下表的星期信息组织起来，输入一个字符串，在表中查找，若存在，输出该字符串在表中的序号，否则输出-1。
(表格详见实验教材P99)
输入输出示例：括号内为说明
输入：
3	(looptimes=3)
Tuesday
Wednesday
year
输出：
3
4
-1*/
#include<stdio.h>
#include<string.h>
void main()
{
	int i,ri,looptimes;
	char *date[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	char str[80];

	scanf("%d",&looptimes);
	getchar();
	for(ri=1;ri<=looptimes;ri++){
		scanf("%s",str);
		if(strcmp(str,date[0])==0)printf("1\n");
		else if(strcmp(str,date[1])==0)printf("2\n");
		else if(strcmp(str,date[2])==0)printf("3\n");
		else if(strcmp(str,date[3])==0)printf("4\n");
		else if(strcmp(str,date[4])==0)printf("5\n");
		else if(strcmp(str,date[5])==0)printf("6\n");
		else if(strcmp(str,date[6])==0)printf("7\n");
		else printf("-1\n");
	}
}


