/*������գ���Ҫ�ı�����������йص���䡣
����һ�������� looptimes (0<looptimes<10)���� looptimes ���������㣺
Ƥ��� height���ף��߶��������£����غ󷴵���ԭ�߶ȵ�һ�룬�����£��ٷ�������������˷�������Ƥ���ڵ� n �����ʱ���ڿ���һ���������پ��룿�� n �η����ĸ߶��Ƕ��٣�(�������1λС��) 
�������ʾ������������˵��
����
3		(looptimes=3)
10  2		(height=10m, n=2)
4   1		(height=2m, n=1)
100 8		(height=100m, n=8)
���
distance=20.0, height=2.5	(��2�����ʱ�����о�������Ϊ20��, ��2�η����߶�Ϊ2.5��)
distance=4.0, height=2.0	(��1�����ʱ�����о�������Ϊ4�ף���1�η����߶�Ϊ2��)
distance=298.4, height=0.4	(��8�����ʱ�����о�������Ϊ298.4�ף���8�η����߶�Ϊ0.4��)*/
#include <stdio.h>
int main(void)
{
    int i, n;
    int looptimes, ri;
    double distance, height,a; 
    scanf("%d", &looptimes);
    for(ri = 1; ri <= looptimes; ri++){distance=0;
        scanf("%lf%d", &height, &n);a=height;
        for(i=1;i<=n;i++){distance+=2*height;
        	height/=2;
        }
        distance-=a;
      	printf("distance = %.1f, height = %.1f\n", distance, height);
   }
}
