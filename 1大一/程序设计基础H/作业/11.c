/*������գ���Ҫ�ı�����������йص���䡣
����һ��������looptimes (0<looptimes<10)����looptimes���������㣺
�������������� m �� n(1<=m,n<=10000)����� m �� n ֮�����е�Fibonacci����
Fibonacci ����(��һ����)��1  1  2  3  5  8  13  21 ......
Ҫ���岢���ú���fib(n)�����Ĺ����Ƿ��ص� n ��Fibonacci���������β�n��������int������������long�����磬fib(7)�ķ���ֵ��13��
���ʹ����䣺printf("%ld ", f);
�������ʾ������������˵��
���룺
3               (looptimes=3)
1 
10            (m=1, n=10)
20 
100          (m=20, n=100)
1000 
6000       (m=1000, n=6000)
�����
1 1 2 3 5 8        (1��10֮���Fibonacci��)
21  34  55  89     (20��100֮���Fibonacci��)
1597  2584  4181   (1000��6000֮���Fibonacci��) */
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


