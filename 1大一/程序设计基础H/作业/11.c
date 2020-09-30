/*程序填空，不要改变与输入输出有关的语句。
输入一个正整数looptimes (0<looptimes<10)，做looptimes次下列运算：
输入两个正整数 m 和 n(1<=m,n<=10000)，输出 m 到 n 之间所有的Fibonacci数。
Fibonacci 序列(第一项起)：1  1  2  3  5  8  13  21 ......
要求定义并调用函数fib(n)，它的功能是返回第 n 项Fibonacci数，函数形参n的类型是int，函数类型是long。例如，fib(7)的返回值是13。
输出使用语句：printf("%ld ", f);
输入输出示例：括号内是说明
输入：
3               (looptimes=3)
1 
10            (m=1, n=10)
20 
100          (m=20, n=100)
1000 
6000       (m=1000, n=6000)
输出：
1 1 2 3 5 8        (1到10之间的Fibonacci数)
21  34  55  89     (20到100之间的Fibonacci数)
1597  2584  4181   (1000到6000之间的Fibonacci数) */
#include "stdio.h"
#include "math.h"
#include "genlib.h"
#include "simpio.h"
int main(void)
{
   int i, m, n;
   int looptimes, ri;
   long f;
   long fib(int n);

   looptimes=GetInteger();
   for(ri = 1; ri <= looptimes; ri++){
        m=GetInteger();
        n=GetInteger();
        for(i=1;fib(i)<=n;i++){
        	if(fib(i)>=m)printf("%ld ", fib(i));
        }
        printf("\n");
    }
}
long fib(int n){
     long a,b,c;int i;
     a=1;b=1;if(n==1||n==2)return 1;
    else{for(i=3;i<=n;i++){
         c=a+b;
         a=b;b=c;
     }
     return c ;
    } 
}


