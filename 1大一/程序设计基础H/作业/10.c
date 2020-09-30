/*程序填空，不要改变与输入输出有关的语句。
输入一个正整数looptimes (0<looptimes<10)，做looptimes次下列运算：
输入两个正整数 a 和 n, 求a＋aa＋aaa＋aa…a(n个a)之和。
要求定义并调用函数fn(a, n)，它的功能是返回 aa…a（n个a），函数形参a和n的类型是int，函数类型是long。例如，fn(3,2)的返回值是33。
输入输出示例：括号内是说明
输入
2       (looptimes=2)
2 
3     (a=2, n=3)
8 
5     (a=8, n=5)
输出
246     (2+22+222)
98760   (8+88+888+8888+88888) */
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
int main(void)
{
    int a, i, n;
    int ri, looptimes;
    long sn;
    long fn(int a, int n);
    looptimes=GetInteger();
    for(ri = 1; ri <= looptimes; ri++){sn=0;
        a=GetInteger();
        n=GetInteger();
        for(i=1;i<=n;i++){
        sn+=fn(a,i)	;
        }
        printf("%ld\n", sn);
    }
}
  long fn(int a,int n){
  	int i ;
  	long b=0;
  	for(i=1;i<=n;i++){
  		b+=a;
  		a*=10;
  	}
  		return b ;
  }
