第一种 
/*程序填空，不要改变与输入输出有关的语句。
验证哥德巴赫猜想：任何一个大于6的偶数均可表示为两个素数之和。例如6=3+3，8=3+5，…，18=7+11。
素数就是只能被1和自身整除的正整数，1不是素数，2是素数。
输入两个正整数 m 和 n(6<=m<=n<=100)，将 m 到 n 之间的偶数表示成两个素数之和，打印时一行打印5组。
要求定义并调用函数 prime(m) 判断m是否为素数，当m为素数时返回1，否则返回0，函数形参 m 的类型是int，函数类型是int。
输出使用语句：printf("%d=%d+%d ", number, i, number-i);
输入输出示例：括号内为说明
输入：
89 
100	(m=89, n=100)
输出：
90=7+83 92=3+89 94=5+89 96=7+89 98=19+79
100=3+97*/
#include "stdio.h"
#include "math.h"
#include "genlib.h"
#include "simpio.h"
int main(void)
{
    int count, i, m, n, x,y;
    int prime(int n); 
    m=GetInteger();
    n=GetInteger();
    count=0;
    if(m % 2 != 0) m = m + 1;
    if(m >= 6){for(i=m;i<=n;i+=2){
    	for(x=2;x<=m;x++)if(prime(x)==1&&prime(i-x)==1){
    		if(count<5){
    			printf("%d=%d+%d ", i, x, i-x);count++;
    		}
			else {
    			printf("%d=%d+%d \n", i, x, i-x);count=0;
    		}
    	}
    }
    }
}
int prime(int n){
	int a,b=1;
	for(a=2;a<sqrt(n);a++){
		if(n%a!=0)b=1;else {
			b=0;break;
		}
		return b;
	}
	
}
第二种： 
/*程序填空，不要改变与输入输出有关的语句。
验证哥德巴赫猜想：任何一个不小于6的偶数均可表示为两个素数之和。例如6=3+3，8=3+5，…，18=7+11。
输入一个正整数looptimes, 做looptimes次重复操作，在每一次中：
输入一个偶数 n(n>=6)，将n表示成两个素数(a,b)之和，要求a<b，输出任意n=a+b的组合，并且一行输 出5组。
输出使用语句：printf("%d=%d+%d ", number, i, number - i);

输入输出示例：括号内为说明
输入：
3                   (looptimes=3，重复3次)
6 
16 
90  	
输出：                                                                                                                             说明(不是输出结果部分)
6=3+3                                                                                                                                    (6对应的结果)
16=3+13 16=5+11                                                                                                              (16对应的结果)
90=7+83 90=11+79 90=17+73 90=19+71 90=23+67                                                 (90对应的结果）
90=29+61 90=31+59 90=37+53 90=43+47*/ 
#include "stdio.h"
#include "math.h"
int isprime(int a);
int main(void)
{
    int count, i, j, k, looptimes, number;
    int a ,b,c;
    scanf("%d",&looptimes);
    for(i=1;i<=looptimes;i++){
      scanf("%d",&number);
      a=3;
      if(number>= 6){
      	count=0;
      	while(a<=number/2){
      		if(count==6){
      		printf("\n");count=0;	
      		}
      		else{
      			if(isprime(a)==1&&isprime(number-a)==1){
      				printf("%d=%d+%d ", number, a, number - a);
      				count++;a+=2;
      			}
      			else a+=2;
      		}
      	}
	  
	   printf("\n");
      
     }
}
}
int isprime(int x){
	int i,flag=1;
	for(i=3;i<x;i+=2){
		if(x%i==0)return 0;
	}
	return 1;
}



 
