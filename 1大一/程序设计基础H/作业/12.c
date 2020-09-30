/*程序填空，不要改变与输入输出有关的语句。
输入一个正整数looptimes (0<looptimes<10)，做 looptimes 次下列运算：
输入两个正整数m和 n(1<=m,n<=1000)，输出 m 到 n 之间的所有完数，完数就是因子和与它本身相等的数（例如，1不是完数，6是完数）。
要求定义并调用函数 factorsum(number)，它的功能是返回number的因子和，函数形参number的类型是整型，函数类型是整型。例如，factorsum(12)的返回值是16(1+2+3+4+6)。
输出使用语句：printf("%d ", i);
输入输出示例：括号内是说明
输入：
2        (looptimes=2)
20 
500   (m=20 n=500)
1 
100    (m=1, n=100)
输出：
28 496   (20到500之间的完数有：28,496)
6 28   (1到100之间的完数有：1,6,28) */
#include "stdio.h"
#include "genlib.h"
#include "simpio.h"
int main(void)
{
    int i, m, n;
    int looptimes, ri;
    int factorsum(int number); 
    
    looptimes=GetInteger();
    for(ri = 1; ri <= looptimes; ri++){
        m=GetInteger();
        n=GetInteger();
        for(i=m;i<=n;i++){
        	if(factorsum(i)==i)printf("%d ", i);
        }
       
      printf("\n");
    }
}
int factorsum(int number){
	int i,a=1;
	for(i=2;i<number;i++){
		if(number%i==0)a+=i;
	}
	return a ;
}



