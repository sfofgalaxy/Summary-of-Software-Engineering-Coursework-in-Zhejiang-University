��һ�� 
/*������գ���Ҫ�ı�����������йص���䡣
��֤��°ͺղ��룺�κ�һ������6��ż�����ɱ�ʾΪ��������֮�͡�����6=3+3��8=3+5������18=7+11��
��������ֻ�ܱ�1��������������������1����������2��������
�������������� m �� n(6<=m<=n<=100)���� m �� n ֮���ż����ʾ����������֮�ͣ���ӡʱһ�д�ӡ5�顣
Ҫ���岢���ú��� prime(m) �ж�m�Ƿ�Ϊ��������mΪ����ʱ����1�����򷵻�0�������β� m ��������int������������int��
���ʹ����䣺printf("%d=%d+%d ", number, i, number-i);
�������ʾ����������Ϊ˵��
���룺
89 
100	(m=89, n=100)
�����
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
�ڶ��֣� 
/*������գ���Ҫ�ı�����������йص���䡣
��֤��°ͺղ��룺�κ�һ����С��6��ż�����ɱ�ʾΪ��������֮�͡�����6=3+3��8=3+5������18=7+11��
����һ��������looptimes, ��looptimes���ظ���������ÿһ���У�
����һ��ż�� n(n>=6)����n��ʾ����������(a,b)֮�ͣ�Ҫ��a<b���������n=a+b����ϣ�����һ���� ��5�顣
���ʹ����䣺printf("%d=%d+%d ", number, i, number - i);

�������ʾ����������Ϊ˵��
���룺
3                   (looptimes=3���ظ�3��)
6 
16 
90  	
�����                                                                                                                             ˵��(��������������)
6=3+3                                                                                                                                    (6��Ӧ�Ľ��)
16=3+13 16=5+11                                                                                                              (16��Ӧ�Ľ��)
90=7+83 90=11+79 90=17+73 90=19+71 90=23+67                                                 (90��Ӧ�Ľ����
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



 
