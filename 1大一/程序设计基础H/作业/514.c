/*������գ���Ҫ�ı�����������йص���䡣
����һ�������� looptimes (0<looptimes<10)���� looptimes ���������㣺
����һ�������� n����� 2/1��3/2��5/3��8/5������ǰn��֮�ͣ�����2λС����(�����дӵ�2����ÿһ��ķ�����ǰһ��������ĸ�ĺͣ���ĸ��ǰһ��ķ���)
�������ʾ������������˵��
����
3        (looptimes=3) 
1        (n=1) 
5        (n=5) 
20       (n=20) 
���
sum = 2.00   	(��1����2.00)
sum = 8.39   	(ǰ5��ĺ���8.39)
sum = 32.66  	(ǰ20��ĺ���32.66*/
#include <stdio.h>
int main(void)
{
    int i, n;
    int looptimes, ri;
    double denominator, numerator, sum, temp;

    scanf("%d", &looptimes);
    for(ri = 1; ri <= looptimes; ri++){
        scanf("%d", &n);denominator=2;numerator=1;
        sum=0;
		for(i=1;i<=n;i++){
			sum+=denominator/numerator;
			temp=denominator;denominator+=numerator;
			numerator=temp;
		} 
     	printf("sum = %.2f\n",sum);
   }
}
