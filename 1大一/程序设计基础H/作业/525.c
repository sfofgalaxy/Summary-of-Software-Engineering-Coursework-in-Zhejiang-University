/*程序填空，不要改变与输入输出有关的语句。
输入一个正整数 looptimes (0<looptimes<10)，做 looptimes 次下列运算：
输入两个正整数 m 和 n(1<=m, n<=1000)，输出 m 到 n之间的所有完数，并输出其因子。一个数如恰好等于它的因子之和，这个数称为完数，例如，1不是完数，6是完数，因为6=1+2+3，其中1、2、3为因子，6为因子和。
输出使用以下语句：
printf("%d = 1", number);
printf(" + %d", factor);
printf("\n");
输入输出示例：括号内为说明
输入：
2          (looptimes=2)
1 30       (m=1, n=30)
400 500    (m=400, n=500)
输出
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
