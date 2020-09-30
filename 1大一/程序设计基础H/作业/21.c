/*程序填空，不要改变与输入输出有关的语句。
输入一个正整数 looptimes (0<looptimes<10)，做 looptimes 次下列运算：
输入精度eps，根据下式求 PI 的值，直到最后一项小于eps。
PI/2＝1＋1/(1*3)＋2!/(1*3*5)＋3!/(1*3*5*7)＋...＋n!/(1*3*5*...*(2n+1))
要求定义并调用函数 fact(n)计算 n!，函数形参n的类型是int，函数类型是double；定义并调用函数 multi(n)计算 1*3*5*...*n，函数形参n的类型是int，函数类型是double。
输入输出示例：括号内是说明
输入：
2           (looptimes=2)
1E-6        (eps=1E-6)
1E-5        (eps=1E-5)
输出示例：
PI = 3.14159
PI = 3.14158*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

double fact(int n);
double multi(int n);	
int main(void)
{	
    int i; 
    int looptimes, ri;
    double eps, sum, item;
    
    looptimes=GetInteger();
    for(ri = 1; ri <= looptimes; ri++){
        eps=GetReal();item=1;i=1;sum=1;
        while(item>=eps){
        		item=fact(i)/multi(2*i+1);sum+=item;i++;
        	}
        	printf("PI = %0.5f\n", 2 * sum);
        }
    }



double fact(int n){
	int i;double s=1;
	for(i=1;i<=n;i++)
	{
	 s*=i;
}
return s;}

double multi(int n){
	int i;double s=1;
	for(i=1;i<=n;i+=2){
		s*=i;
	}
	return s; 
}
