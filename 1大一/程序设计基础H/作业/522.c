/*������գ���Ҫ�ı�����������йص���䡣
����һ�������� looptimes (0<looptimes<10)���� looptimes ���������㣺
ĳ������ͨ���⳵�շѱ�׼���£�"�����3����𲽷�10Ԫ��������̵��������10�����ڣ�ÿ�������2Ԫ��
����̳���10�������ϵĲ��ּ���50%�Ļؿղ����ѣ���ÿ�������3Ԫ��Ӫ�˹����У���·�輰�˿�Ҫ����ʱͣ���ģ�
ÿ5���Ӱ�1������Ѽ��ա��˼ۼƷ�β���������룬������Ԫ��"
��д����������ʻ���(����)��ȴ�ʱ��(����)�����㲢����˿�Ӧ֧���ĳ���(Ԫ)��
3  	    (looptimes=3) 
1.6 2 52    (��ʻ1.6����,�ȴ�2��52��)
3.1 6 15    (��ʻ3.1����,�ȴ�6��15��)
11.8 2 30   (��ʻ11.8����,�ȴ�2��30��)
���
cost = 10
cost = 13
cost = 31
*/
#include <stdio.h>
int main(void)
{
    int looptimes, ri;
    int minutes, seconds;
    double cost, mile;
	int a;
    scanf("%d", &looptimes);
    for(ri = 1; ri <= looptimes; ri++){
        scanf("%lf%d%d", &mile, &minutes, &seconds);
         seconds=seconds+minutes*60;
         mile=mile+seconds/300.0;
         if(mile<=3){
         	cost=10;
         }
         else if(mile<=10){
         	cost=10+(mile-3)*2;
         }
         else{
         	cost=24+(mile-10)*3;
         }
	printf("cost = %.0f\n", cost);
    }
}
