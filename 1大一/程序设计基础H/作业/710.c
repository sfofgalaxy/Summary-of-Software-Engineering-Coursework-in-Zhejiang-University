/*������գ���Ҫ�ı�����������йص���䡣
����һ�������� looptimes (0<looptimes<10)���� looptimes ���������㣺
����һ���ַ��� str��������һ���ַ� c�����ַ��� str �г��ֵ������ַ� c ɾ����
Ҫ���岢���ú���delchar(str,c), ���Ĺ����ǽ��ַ��� str �г��ֵ����� c �ַ�ɾ���������β�str���������ַ�ָ�룬�β�c��������char������������void��
�������ʾ����������Ϊ˵��
����
3               (looptimes=3��
happy new year  (�ַ���"happy new year")
a               (��ɾ�����ַ�'a')
bee             (�ַ���"bee")
e               (��ɾ�����ַ�'e')
111211          (�ַ���"111211")
1               (��ɾ�����ַ�'1')
���
result: hppy new yer    (�ַ���"happy new year"�е��ַ�'a'����ɾ��)
result: b               (�ַ���"bee"�е��ַ�'e'����ɾ��)
result: 2               (�ַ���"111211"�е��ַ�'1'����ɾ��)*/
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

