/*������գ���Ҫ�ı�����������йص���䡣
����һ��������looptimes (0<looptimes<10)����looptimes���������㣺
����һ��ָ�����齫�±��������Ϣ��֯����������һ���ַ������ڱ��в��ң������ڣ�������ַ����ڱ��е���ţ��������-1��
(������ʵ��̲�P99)
�������ʾ����������Ϊ˵��
���룺
3	(looptimes=3)
Tuesday
Wednesday
year
�����
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


