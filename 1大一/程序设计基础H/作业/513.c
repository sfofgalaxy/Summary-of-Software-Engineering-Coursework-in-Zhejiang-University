/*������գ���Ҫ�ı�����������йص���䡣
����һ�������� looptimes (0<looptimes<10)���� looptimes ���������㣺
����һ������ in��������λ���Լ���λ����֮�͡����� 123 �ĸ�λ����֮���� 6��λ���� 3��
�������ʾ������������˵��
����
4        (looptimes=4) 
0        (in=0) 
23456    (in=23456) 
-100     (in=-100) 
-1       (in=-1) 
���
count = 1, sum = 0 	(0��λ����1, ��λ����֮����0)
count = 5, sum = 20 	(23456��λ����5, ��λ����֮����20)
count = 3, sum = 1 	(-100��λ����3, ��λ����֮����1)
count = 1, sum = 1 	(-1��λ����1, ��λ����֮����1)
*/
#include <stdio.h>
int main(void)
{
    int count, in,sum;
    int looptimes, ri;

    scanf("%d", &looptimes);
    for(ri = 1; ri <= looptimes; ri++){
     	scanf("%d", &in);count=0;sum=0;
        if(in<0)in=-in;
        do{
        	sum+=in%10;
        	in/=10;
        	count++;
        }
        while(in>0);
     	printf("count = %d, sum = %d\n", count, sum);
   }
}
