/*������գ���Ҫ�ı�����������йص���䡣
����һ�������� looptimes (0<looptimes<10)���� looptimes ���������㣺
�������������� m �� n(1<=m, n<=1000)����� m �� n֮�����������������������ӡ�һ������ǡ�õ�����������֮�ͣ��������Ϊ���������磬1����������6����������Ϊ6=1+2+3������1��2��3Ϊ���ӣ�6Ϊ���Ӻ͡�
���ʹ��������䣺
printf("%d = 1", number);
printf(" + %d", factor);
printf("\n");
�������ʾ����������Ϊ˵��
���룺
2          (looptimes=2)
1 30       (m=1, n=30)
400 500    (m=400, n=500)
���
result:
6 = 1 + 2 + 3
28 = 1 + 2 + 4 + 7 + 14
result:
496 = 1 + 2 + 4 + 8 + 16 + 31 + 62 + 124 + 248*/
#include <stdio.h>
int main(void)
{
    int factor, m, n, number, sum;
    int looptimes, ri;
    scanf("%d",&looptimes);
    for(ri = 1; ri <= looptimes; ri++){
        scanf("%d%d", &m, &n);
        printf("result:\n"); 
        for(number=m;number<=n;number++){sum=1;
        	for(factor=2;factor<number;factor++){
        		if(number%factor==0)sum+=factor;
        	}
        	if(number!=1&&sum==number){printf("%d = 1",number);for(factor=2;factor<number;factor++){
        		if(number%factor==0)printf(" + %d", factor);
        	}
        	printf("\n");
        	}
        	
        }
    }
}
