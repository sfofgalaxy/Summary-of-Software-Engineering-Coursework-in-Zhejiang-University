/*������գ���Ҫ�ı�����������йص���䡣
����һ�������� looptimes (0<looptimes<10)���� looptimes ���������㣺
����1 ������in��������һ������digit(0��digit<10)��ͳ�Ʋ�������� in ������ digit �ĸ�����
Ҫ���岢���ú���countdigit(number,digit)�����Ĺ�����ͳ������ number ������ digit �ĸ��� ,�����β�number��digit��������int������������int�����磬countdigit(10090,0)�ķ���ֵ��3��
�������ʾ������������˵��
����
2         (looptimes=2)
21252 2   (number=21252, digit=2)
-1111 9   (number=-1111, digit=9)
���
Number 21252 of digit 2: 3       (21252����3��2)
Number -1111 of digit 9: 0       (-1111����0��9)*/
#include "stdio.h"
int main(void)
{
    int count, digit, in; 
    int looptimes, ri;
    int countdigit(int number, int digit);

    scanf("%d",&looptimes);
    for(ri = 1; ri <= looptimes; ri++){
        scanf("%d%d", &in, &digit);
        count=countdigit(in,digit);
        printf("Number %d of digit %d: %d\n", in, digit, count);
    }
}
int countdigit(int number,int digit){
	int a;a=0;if(number<0)number=-number;
	do{
		if(number%10==digit)a++;
		number/=10;
		
	}while(number>0);
	return a;
}
