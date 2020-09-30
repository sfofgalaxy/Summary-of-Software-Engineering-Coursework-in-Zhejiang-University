/*������գ���Ҫ�ı�����������йص���䡣
����һ�������� looptimes (0<looptimes<10)���� looptimes ���������㣺
���뾫��eps��������ʽ�� PI ��ֵ��ֱ�����һ��С��eps��
PI/2��1��1/(1*3)��2!/(1*3*5)��3!/(1*3*5*7)��...��n!/(1*3*5*...*(2n+1))
Ҫ���岢���ú��� fact(n)���� n!�������β�n��������int������������double�����岢���ú��� multi(n)���� 1*3*5*...*n�������β�n��������int������������double��
�������ʾ������������˵��
���룺
2           (looptimes=2)
1E-6        (eps=1E-6)
1E-5        (eps=1E-5)
���ʾ����
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
