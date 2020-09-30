/*程序填空，不要改变与输入输出有关的语句。
输入一个正整数looptimes (0<looptimes<10)，做looptimes次下列运算：
输入一个整数 in，输出其逆序数。
要求定义并调用函数reverse(number)，它的功能是返回number的逆序数，函数形参number的类型是int，函数类型是int。例如，reverse(12345)的返回值是54321。
输入输出示例：括号内是说明
输入
5        (looptimes=4) 
12345    (in=12345) 
-100     (in=-100) 
-2       (in=-2) 
99       (in=99) 
0        (in=0) 
输出
54321    (12345的逆序数)
-1       (-100的逆序数)
-2       (-2的逆序数)
99       (99的逆序数)
0        (0的逆序数)*/ 

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
int fun(int n);
int fn(int n);
int main()
{	
    int m1,m2;
    
    m1=GetInteger();
    m2=GetInteger();
  
    printf("%d--->%d\n", m1, fun(m1));  
    printf("%d--->%d\n", m2, fun(m2));  

}
int fun(int n){
	int i,a,b,c,d,e ;e=n;
	i=0;b=0;if(n>=0)n=n;else n=-n;a=n;
	do {
		i++;n/=10;
	}
	while(n>0);
     for(d=1;d<=i;d++){c=a%10;a/=10;
     	b+=c*fn(i-d);
     }
     if(e>=0)return b;
     else return -b;
}
 int fn(int n){
 	int i,a=1;
 	for(i=1;i<=n;i++){
 		a*=10;
 	}
 	return a;
 }


