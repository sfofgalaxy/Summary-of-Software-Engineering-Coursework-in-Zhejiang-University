/*������գ���Ҫ�ı�����������йص���䡣
����һ��������looptimes (0<looptimes<10)����looptimes���������㣺
����2�������� m �� n(m<=n)��������ʽ 1/m + 1/(m+1) + 1/(m+2) + ...... + 1/n��ֵ�����ʱ����3λС����
�������ʾ����������Ϊ˵��
����
3        (looptimes=3)
5 15     (����1/5+1/6+1/7+...+1/15)
10 20    (����1/10+1/11+1/12+...+1/20)
1 3      (����1+1/2+1/3)
���
sum = 1.235
sum = 0.769
sum = 1.833
*/
#include <stdio.h>
int main(void)
{   
    int i, m, n;
    int looptimes, ri;
    double sum;
    scanf("%d", &looptimes);
    for(ri = 1; ri <= looptimes; ri++){
    	     sum=0; 
        scanf("%d%d", &m, &n);	
        for(i=m;i<=n;i++)
		{
        	sum+=1.0/i;
        }
        printf("sum = %.3f\n", sum);
    }    	 
}
